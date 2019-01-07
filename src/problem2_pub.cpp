#include <ros/ros.h>
#include <cstdlib>
#include "problem2_1/problem2_msg.h"


int main(int argc, char *argv[]){
    ros::init(argc, argv, "problem2_pub");
    ros::NodeHandle nh;
    
    ros::Publisher pub = nh.advertise<problem2_1::problem2_msg>("problem2",10);
    ros::Rate loop_rate(10);
    problem2_1::problem2_msg msg;

    srand(time(NULL));
    u_int16_t num;
    u_int16_t num2;
    //std::vector<u_int16_t>::iterator i;
    
    while(ros::ok())
    {
        msg.stamp = ros::Time::now();
        num = rand() % 20 + 1;
        msg.v.assign(num,0);
        msg.r = num;
       /* i = msg.v.begin();
        while(i != msg.v.end()){
            num2 = rand() % 20 + 1;
            *i = num2;
            i++;
        }*/
        for(size_t i = 0; i < msg.v.size(); ++i){
            msg.v[i] = rand() % 20 +1;
            i++;
        }
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
  
}
