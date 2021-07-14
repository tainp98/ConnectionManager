#ifndef EYEPHOENIXPROTOCOL_H
#define EYEPHOENIXPROTOCOL_H

/** ======================================================================
 *
 * CHANGE LOG:
 *
 *  - 02/08/2018 - DanDo: Add <TrackingResponse:enum> opcode to IPC Data
 *
 * =======================================================================
 */
enum class EyePhoenixProtocol{
    //MotionC
    SetFreePanTilt = 0x00A1,
    SetPanScan = 0x00A2,
    StartRecord = 0x00A3,
    StopRecord = 0x00A4,
    SetPanTiltRateFactor = 0x0001,
    SetTrackPosition = 0x00A0,
    SetPanTiltAngle = 0x000E,
    SetPanTiltAngleDiff = 0xFFF1,
    SetRapidView = 0x0005,
    GimbalStab = 0x000B,
    SetCalib = 0x000D,
    // IPC
    SensorChange = 0x0006,
    LockModeChange = 0x0007,
    TakeSnapShot = 0x0004,
    ChangeSensorColor = 0x0008,
    RFRequest = 0xFFF2,
    GimbalRecord = 0x0009,
    ScreenPress = 0x0002,
    EOOpticalZoom = 0x0000,
    E0DigitalZoom = 0xFFF3,
    EOZoomStatus = 0x0100,

    IROpticalZoom = 0x0018,

    RFResponse = 0xFFF4,
    GimbalMode = 0x000A,
    ImageStab = 0xFFF5,
    GPSData = 0x0003,
    SceneSteering = 0x000F,
    Tracking = 0x0010,
    TrackingSize = 0x0012,

    // System
    RequestResponse = 0xFFF6,
    CameraInstall = 0xFFF7,
    SystemStatus = 0x000C,
    Confirm = 0x010A,
    ErrorMessage = 0x010B,
    StreamingProfile = 0x010C,

    // Control Pan/Tilt
//    MotionRate = 0x0401,
    MotionAngle = 0x0406,
//    MotionRequest = 0x0403,
//    MotionACPanRate = 0x0404,
//    MotionACTiltRate = 0x0405,
    MotionACBottomRate = 0x04A,
//    MotionFree = 0x0407,
//    MotionCResponse = 0x0409,
    SetMotionAnglePan = 0x0406,

    MotionScan = 0x0401,
    MotionACPanRate = 0x0402,
    MotionACTiltRate = 0x0402,
    MotionRequest = 0x0403,
    MotionCResponse = 0x0404,
    MotionFree = 0x0405,
//    MotionAngle = 0x0406,
    MotionJS = 0x0407,

    // IPC Data
    IPCStatusResponse = 0x0200,
    MotionDataResponse = 0x0201,
    SteeringResponse = 0x0202,
    TrackingResponse = 0x0203,

    //AP data
    ExternalAttitude = 0xBD,
    ExternalPosition = 0xBE,
    Telemetry = 0x0101,

    //GCS
    TargetPosition = 0x0500,
    MotionCStatus = 0x0501,
    GeolockInfo = 0x0502,

    //Hitachi Configuration
    HitachiConfig = 0x0606,
    GLConfig = 0x0607,

    //IMU
    IMUData = 0x0701,
    IMUReset = 0x0761,
    IMUCalib = 0x0763,

    //IR CONFIG
    IRConfig = 0x55AA,
    IRSetStatus = 0xAA55
};

#endif // EYEPHOENIXPROTOCOL_H
