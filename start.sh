#!/bin/bash

SESSION="glider"
SESSIONEXISTS=$(tmux list-sessions | grep $SESSION)
ROS_WS="glider_ws"

if [ -z "$SESSIONEXISTS" ]
then
    tmux new-session -d -s $SESSION

    tmux rename-window -t $SESSION:0 'Main'
    tmux send-keys -t $SESSION:0.0 'cd ~/${ROS_WS}' C-m '. install/local_setup.bash' C-m

    tmux split-window -v -t $SESSION:0.0
    tmux select-pane -t $SESSION:0.1
    tmux send-keys -t $SESSION:0.1 'cd ~/${ROS_WS}' C-m '. install/local_setup.bash' C-m 'ros2 topic echo /servo_publisher' C-m
    tmux select-pane -T "Servo overview"

    tmux split-window -h -t $SESSION:0.1
    tmux select-pane -t $SESSION:0.2
    tmux send-keys -t $SESSION:0.2 'sudo pigpiod' C-m 'Drone2024.' C-m 'cd ~/${ROS_WS}' C-m '. install/local_setup.bash' C-m 'ros2 run servo_controller servo_control_node' C-m
    tmux select-pane -T "Servo control"

    tmux select-layout -t $SESSION:0 main-vertical

    width=$(($(tmux display -p '#{window_width}') * 35 / 100))
    tmux resize-pane -t $SESSION:0.1 -x $width
    tmux resize-pane -t $SESSION:0.2 -x $width

fi

tmux attach -t $SESSION:0.0
