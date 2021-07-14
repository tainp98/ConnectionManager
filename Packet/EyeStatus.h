#ifndef EYESTATUS_H
#define EYESTATUS_H

#include "Common_type.h"

using namespace Eye;
namespace Status {
    enum class RecordMode : unsigned char {
        OFF = 0,
        ON = 1
    };
    enum class HorizonMode : unsigned char{
        OFF = 0,
        ON = 1
    };
    enum class DetectMode : unsigned char{
        OFF = 0,
        ON = 1
    };
    enum class TrackMode : unsigned char{
        OFF = 0,
        ON = 1
    };
    enum class DetectTrackMode : unsigned char{
        Idle = 0,
        Detect = 1,
        Track = 2,
    };
    enum class MotionCMode : unsigned char{
        Idle = 0,
        Scan = 1,
        Track = 2,
    };
    enum class LockMode : unsigned char{
        Idle = 0,
        Scan = 1,
        Track = 2,
        Stop = 3,
    };
    typedef struct
    {
        bool started = false;
        bool detected = false;
        bool cancelled = false;
        bool lostTrack = false;

    } MCFlag;

    typedef struct
    {
        bool started = false;
        bool detected = false;
        bool cancelled = false;
        bool lostTrack = false;

    } AFlag;
    typedef struct
    {
        //
        //===== Sensor parameters and status
        //
        data_type MAX_HFOVEO = 25.75/180.0*M_PI;
        data_type MAX_HFOVIR = 25.75/180.0*M_PI;
        data_type MIN_HFOVEO = 3.336/180.0*M_PI;
        data_type MIN_HFOVIR = 3.92/180.0*M_PI;
        data_type freeMemory;
        data_type totalMemory;
        data_type hfovEO = 52.75/180.0*M_PI;
        data_type hfovIR = 26.39/180.0*M_PI;
        data_type focalLengthEO = 0.0;
        data_type focalLengthIR = 0.0;
        index_type eoIndex = -1;
        index_type irIndex = -1;

        unsigned int m_sentIRAddr;
        unsigned int m_revIRAddr;

        //phongml track
        data_type trackPx;
        data_type trackPy;
        data_type trackJx;
        data_type trackJy;
        data_type scanPos;
        data_type scanVel;
        index_type scanRange;
        bool newScan;
        //
        //===== Joystick system status
        //
        index_type joyID;
    } IPCStatus;

    typedef struct{
        data_type MAX_RATE = 120.0/180.0*M_PI;
        data_type panCurrentVelocity;
        data_type tiltCurrentVelocity;
        data_type panCurrentPosition;
        data_type tiltCurrentPosition;
    } MotionCStatus;

    typedef struct{
        data_type panPos;
        data_type currPanPos;
        data_type panVel;
        data_type tiltPos;
        data_type tiltVel;
        data_type fov;
        RecordMode recordMode;
        HorizonMode horizonMode;
        DetectMode detectMode;
        TrackMode trackMode;
        DetectTrackMode detectTrackMode;
        MotionCMode motionCMode;
        LockMode lockMode;
        unsigned int freq = 100;
        byte stopFlag = 0;
        bool usingZoomInIR = false;
        bool usingZoomOutIR = false;
    } SystemStatus;

    class EyeStatus {
    public:
        EyeStatus(){}
        ~EyeStatus(){}

    public:
        MotionCStatus MotionC;
        IPCStatus IPC;
        SystemStatus System;
        MCFlag mcFlag;
        AFlag aFlag;
    };
}

#endif // EYESTATUS_H
