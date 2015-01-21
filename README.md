# ![Officine Robotiche][Logo] - µNAV
This is a project in development by [Officine Robotiche] to control motors.

## **The [uNAV board](https://github.com/officinerobotiche/uNAVPCB) is HERE!**

# Release
- [**Download last stable release**](https://github.com/officinerobotiche/uNAV.X/releases)
- [wiki] with all detailed information about firmware

# Firmware features
- High speed DC motor control **1KHz**
- High speed serial communcation **115200bps**

## DC Motor control
- Velocity PID control
- Encoders management (A and B channels) 
- Motors current measurement
- Enable H-Bridge

## Communications
- *OR-B* Library communication for **serial communication**
  - You can send different type of messages to control or set board
- **I2C** Communication (To be implemented)

## Boards compliant
- [uNAV](https://github.com/officinerobotiche/uNAVPCB)
- [RoboController](http://tuttoelettronica.net/archives/455)
- [Motion Control](http://raffaello.officinerobotiche.it/schede-elettroniche/motion-control/)

#Tech
- Show the current state: [Network](https://github.com/officinerobotiche/uNAV.X/network)
- Open an [issue](https://github.com/officinerobotiche/uNAV.X/issues) about firmware
- [Milestone](https://github.com/officinerobotiche/uNAV.X/milestones)  for a version of code

## Repository policy
This repository follow **[Git flow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow)** policy:
![Gitflow](https://raw.githubusercontent.com/quickhack/translations/master/git-workflows-and-tutorials/images/git-workflows-gitflow.png)

- **[GREEN] Master** branch stores the official release history
- **[ORANGE] Develop** branch serves as an integration branch for features
- **[BLUE] Feature** branches use *develop* as their parent branch
- **[YELLOW] Release-*** No new features can be added after this point—only bug fixes
- **[GREY] Hotfix** branches are used to quickly patch production releases

## Communication libraries
- [C++](https://github.com/officinerobotiche/orblibcpp)
- [Java](https://github.com/officinerobotiche/orblibjar)
- [ROS (Robotic Operative System)](https://github.com/officinerobotiche/serial_bridge)
 
## Software
- [PID tuning](https://github.com/officinerobotiche/uNav_PID_Tuner)

[wiki]:http://wiki.officinerobotiche.it/
[Officine Robotiche]:http://www.officinerobotiche.it/
[Logo]:http://2014.officinerobotiche.it/wp-content/uploads/sites/4/2014/09/ORlogoSimpleSmall.png
