// header file that provides definitions and support for inverse kinematics
// operations

// the internal position of the robot
struct IKDirectionPos {

  float angle; // our current angle on the Y axis. On boot this is 0

};

// the maximum shoulder rotation for Stompy
const int MAX_SHOULDER_ROTATION = 135;
const int MIN_SHOULDER_ROTATION = 45;

// the elbow rotation max and min as well - these don't have
// the same structural limitations as the shoulder joints on Stompy's
// chassis, but setting the values low help us conserve delta-rot energy
const int MAX_ELBOW_ROTATION = 135;
const int MIN_ELBOW_ROTATION = 45;
