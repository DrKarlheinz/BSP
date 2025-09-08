# vrpn_mocap_px4

Relay UAV's pose from Optitrack in FLU frame to PX4 in NED/FRD frame

To relay the pose, launch vrpn first using

```
ros2 launch vrpn_mocap client.launch.yaml server:=192.168.30.105 port:=3883
```

Then, run the node using

```
ros2 run vrpn_mocap_px4 relay_pose --ros-args -p source:=/vrpn/hummingbird/pose -p sink:=/fmu/in/vehicle_visual_odometry
```
or launch using
```

ros2 launch vrpn_mocap_px4 launch.yaml source:=/vrpn/hummingbird/pose sink:=/fmu/in/vehicle_visual_odometry
```

Don't run both commands. Replace source and sink topics accordingly