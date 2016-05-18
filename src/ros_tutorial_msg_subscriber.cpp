// ROSメインヘッダーファイル
// ROSプログラミングを行う際に必要となるROSファイルのインクルードを行う。
// 後述するROS_INFO関数などを使用できるようになる。
#include "ros/ros.h"
// msgTutorialメッセージファイルのヘッダー
// CMakelists.txtでビルド後に自動的に生成されるように設定した
// メッセージファ//イルのヘッダーをインクルードする。
#include "irvs_ros_tutorials/msgTutorial.h"
// メッセージを受信したときに動作するコールバック関数を定義
// irvs_ros_tutorialsパッケージのmsgTutorialメッセージを受信する
// 受信したメッセージを表示する。
void msgCallback(const irvs_ros_tutorials::msgTutorial::ConstPtr& msg)
{

ROS_INFO("recieve msg: %d", msg->data);
}
// 購読者ノードのメイン関数
int main(int argc, char **argv)
{
// ノード名の初期化
ros::init(argc, argv, "ros_tutorial_msg_subscriber");
// ROSシステムとの通信のためのノードのハンドルを宣言
ros::NodeHandle nh;
// 購読者ノードの宣言
// irvs_ros_tutorialsパッケージのmsgTutorialメッセージファイルを
// 利用した購読者ros_tutorial_subを宣言する。
// トピック名をros_tutorial_msg とし、購読者キュー( queue )の
// サイズを100に設定する。
// 購読者キューには、配信者から送信されてくるメッセージが蓄積される。
ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg",100, msgCallback);
// メッセージが受信されるまで待機し、受信が行われた場合、
// コールバック関数を実行する。
ros::spin();
return 0;
}
