cmake_minimum_required (VERSION 2.8.3)
project(irvs_ros_tutorials)
## catkinビルドに必要なコンポーネントパッケージの設定
## これらのパッケージが存在しない場合、catkinビルドの途中でエラーが出る。
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)
## メッセージファイルの設定
add_message_files(FILES msgTutorial.msg)
## add_message_filesで使用するメッセージの依存関係を設定
## これらのパッケージが存在しない場合、catkinビルドの途中でエラーが出る。
generate_messages(DEPENDENCIES std_msgs)
## インクルードディレクトリ、ライブラリ、catkinビルド、システムに依存するパッケージの指定
catkin_package(
INCLUDE_DIRS include
LIBRARIES irvs_ros_tutorials
CATKIN_DEPENDS roscpp std_msgs
DEPENDS system_lib
)
## インクルードディレクトリの設定
include_directories(include ${catkin_INCLUDE_DIRS})
## ros_tutorial_msg_publisherノードの設定
## 実行ファイル、ターゲットリンクライブラリ、追加の依存関係などを設定
add_executable(ros_tutorial_msg_publisher
src/ros_tutorial_msg_publisher.cpp)
target_link_libraries(ros_tutorial_msg_publisher ${catkin_LIBRARIES})
add_dependencies(ros_tutorial_msg_publisher
irvs_ros_tutorials_generate_messages_cpp)
## ros_tutorial_msg_subscriberノードの設定
## 実行ファイル、ターゲットリンクライブラリ、追加の依存関係などを設定
add_executable(ros_tutorial_msg_subscriber
src/ros_tutorial_msg_subscriber.cpp)
target_link_libraries(ros_tutorial_msg_subscriber ${catkin_LIBRARIES})
add_dependencies(ros_tutorial_msg_subscriber
irvs_ros_tutorials_generate_messages_cpp)
