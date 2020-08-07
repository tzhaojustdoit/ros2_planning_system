// Copyright 2019 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PLANSYS2_BT_ACTIONS__BTACTION_HPP_
#define PLANSYS2_BT_ACTIONS__BTACTION_HPP_

#include <string>

#include "behaviortree_cpp_v3/behavior_tree.h"
#include "behaviortree_cpp_v3/bt_factory.h"
#include "behaviortree_cpp_v3/xml_parsing.h"

#include "plansys2_executor/ActionExecutorClient.hpp"
#include "rclcpp/rclcpp.hpp"

namespace plansys2
{

class BTAction : public plansys2::ActionExecutorClient
{
public:
  explicit BTAction(
    const std::string & action,
    const std::string & bt_xml_file,
    const std::vector<std::string> & plugin_list,
    float rate = 5);

  const std::string & getActionName() const {return action_;}
  const std::string & getBTFile() const {return bt_xml_file_;}

protected:
  virtual void atStart();
  virtual void actionStep();
  bool isFinished();

  BT::BehaviorTreeFactory factory_;

private:
  BT::Tree tree_;

  std::string action_;
  std::string bt_xml_file_;

  bool finished_;
};

}  // namespace plansys2

#endif  // PLANSYS2_PROBLEM_EXPERT__PROBLEMEXPERT_HPP_
