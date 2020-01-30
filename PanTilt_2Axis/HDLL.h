enum EEP_REGISTER
{
	EEP_MODEL_NO_1 = 0,
	EEP_MODEL_NO_2 = 1,
	EEP_VERSION_1 = 2,
	EEP_VERSION_2 = 3,
	EEP_BAUD_RATE = 4,
	EEP_REASERVED_1 = 5,
	EEP_ID = 6,
	EEP_ACK_POLICY = 7,
	EEP_ALARM_LED_POLICY = 8,
	EEP_TORQUE_POLICY = 9,
	EEP_RESERVED_2 = 10,
	EEP_MAX_TEMPERATURE = 11,
	EEP_MIN_VOLTAGE = 12,
	EEP_MAX_VOLTAGE = 13,
	EEP_ACCELERATION_RATIO = 14,
	EEP_MAX_ACCELERATION_TIME = 15,
	EEP_DEAD_ZONE = 16,
	EEP_SATURATOR_OFFSET = 17,
	EEP_SATURATOR_SLOPE = 18,
	EEP_PWM_OFFSET = 20,
	EEP_MIN_PWM = 21,
	EEP_MAX_PWM = 22,
	EEP_OVERLOAD_PWM_THRESHOLD = 24,
	EEP_MIN_POSITION = 26,
	EEP_MAX_POSITION = 28,
	EEP_POSITION_KP = 30,
	EEP_POSITION_KD = 32,
	EEP_POSITION_KI = 34,
	EEP_POSITION_FEEDFORWARD_1ST_GAIN = 36,
	EEP_POSITION_FEEDFORWARD_2ND_GAIN = 38,
	EEP_RESERVED_3 = 40,
	EEP_RESERVED_4 = 42,
	EEP_VELOCITY_KP = 38,
	EEP_VELOCITY_KD = 40,
	EEP_VELOCITY_KI = 42,
	EEP_LED_BLINK_PERIOD = 44,
	EEP_ADC_FAULT_CHECK_PERIOD = 45,
	EEP_PACKET_GARBAGE_CHECK_PERIOD = 46,
	EEP_STOP_DETECTION_PERIOD = 47,
	EEP_OVELOAD_DETECTION_PERIOD = 48,
	EEP_STOP_THRESHOLD = 49,
	EEP_INPOSITION_MARGIN = 50,
	EEP_RESERVED_5 = 51,
	EEP_RESERVED_6 = 52,
	EEP_CALIBRATION_DIFFERENCE = 53,
	EEP_LAST = EEP_CALIBRATION_DIFFERENCE
};

enum RAM_REGISTER
{
	RAM_ID = 0,
	RAM_ACK_POLICY = 1,
	RAM_ALARM_LED_POLICY = 2,
	RAM_TORQUE_POLICY = 3,
	RAM_RESERVED_2 = 4,
	RAM_MAX_TEMPERATURE = 5,
	RAM_MIN_VOLTAGE = 6,
	RAM_MAX_VOLTAGE = 7,
	RAM_ACCELERATION_RATIO = 8,
	RAM_MAX_ACCELERATION_TIME = 9,
	RAM_DEAD_ZONE = 10,
	RAM_SATURATOR_OFFSET = 11,
	RAM_SATURATOR_SLOPE = 12,
	RAM_PWM_OFFSET = 14,
	RAM_MIN_PWM = 15,
	RAM_MAX_PWM = 16,
	RAM_OVERLOAD_PWM_THRESHOLD = 18,
	RAM_MIN_POSITION = 20,
	RAM_MAX_POSITION = 22,
	RAM_POSITION_KP = 24,
	RAM_POSITION_KD = 26,
	RAM_POSITION_KI = 28,
	RAM_POSITION_FEEDFORWARD_1ST_GAIN = 30,
	RAM_POSITION_FEEDFORWARD_2ND_GAIN = 32,
	RAM_RESERVED_3 = 34,
	RAM_RESERVED_4 = 36,
	RAM_VELOCITY_KP = 32,
	RAM_VELOCITY_KD = 34,
	RAM_VELOCITY_KI = 36,
	RAM_LED_BLINK_PERIOD = 38,
	RAM_ADC_FAULT_CHECK_PERIOD = 39,
	RAM_PACKET_GARBAGE_CHECK_PERIOD = 40,
	RAM_STOP_DETECTION_PERIOD = 41,
	RAM_OVELOAD_DETECTION_PERIOD = 42,
	RAM_STOP_THRESHOLD = 43,
	RAM_INPOSITION_MARGIN = 44,
	RAM_TURN = 45, //RAM_RESERVED_5
	RAM_CALIBRATION__DIFFERENCE_L = 46,
	RAM_CALIBRATION__DIFFERENCE_H = 47,
	RAM_STATUS_ERROR = 48,
	RAM_STATUS_DETAIL = 49,
	RAM_RESERVED_7 = 50,
	RAM_RESERVED_8 = 51,
	RAM_TORQUE_CONTROL = 52,
	RAM_LED_CONTROL = 53,
	RAM_VOLTAGE = 54,
	RAM_TEMPERATURE = 55,
	RAM_CURRENT_CONTROL_MODE = 56,
	RAM_TICK = 57,
	RAM_CALIBRATED_POSITION = 58,
	RAM_ABSOLUTE_POSITION = 60,
	RAM_DIFFERENTIAL_POSITION = 62,
	RAM_PWM = 64,
	RAM_RESERVED_9 = 66,
	RAM_ABSOLUTE_GOAL_POSITION = 68,
	RAM_ABSOLUTE_DESIRED_TRAJECTORY_POSITION = 70,
	RAM_DESIRED_VELOCITY = 72,
	RAM_LAST = RAM_DESIRED_VELOCITY
};

//// [Open DLL Function] //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************************************************************************************/
// S_JOG Move Struct Define
typedef struct CMD_SJog
{
	short Value;
	unsigned char Stop;
	unsigned char InfiniteTurn;
	unsigned char LED;
	unsigned char NoAction;
	unsigned char ID;
	unsigned char Padding0;
	unsigned char Profile; 
	unsigned char Padding1;
	unsigned char Padding2;
	unsigned char Padding3;
	unsigned char Padding4;
	unsigned char Padding5;
	unsigned char Padding6;
	unsigned char Padding7;
}CMD_SJog;

// I_JOG Move Struct Define
typedef struct CMD_IJog
{
	short Value;
	unsigned char Stop;
	unsigned char InfiniteTurn;
	unsigned char LED;
	unsigned char NoAction;
	unsigned char ID;
	unsigned char PlayTime_ms;
	unsigned char Profile; 
	unsigned char Padding1;
	unsigned char Padding2;
	unsigned char Padding3;
	unsigned char Padding4;
	unsigned char Padding5;
	unsigned char Padding6;
	unsigned char Padding7;
}CMD_IJog;

// MS_JOG Move Struct Define -> Only available on New HerkuleX Model
typedef struct CMD_MSJog
{
	short Value;
	unsigned char Stop;
	unsigned char InfiniteTurn;
	unsigned char LED;
	unsigned char NoAction;
	unsigned char ID;
	unsigned char Padding0;
	unsigned char Profile;
	unsigned char Padding1;
	unsigned char Padding2;
	unsigned char Padding3;
	unsigned char Padding4;
	unsigned char Padding5;
	unsigned char Padding6;
	unsigned char Padding7;
}CMD_MSJog;

// MI_JOG Move Struct Define -> Only available on New HerkuleX Model
typedef struct CMD_MIJog
{
	short Value;
	unsigned char Stop;
	unsigned char InfiniteTurn;
	unsigned char LED;
	unsigned char NoAction;
	unsigned char ID;
	unsigned char PlayTime_ms;
	unsigned char Profile;
	unsigned char Padding1;
	unsigned char Padding2;
	unsigned char Padding3;
	unsigned char Padding4;
	unsigned char Padding5;
	unsigned char Padding6;
	unsigned char Padding7;
}CMD_MIJog;
/************************************************************************************************************************************************************/

/************************************************************************************************************************************************************/
//Serial Communication Connect & Disconnect//
extern "C" __declspec(dllimport) BOOL Connect(UINT uPortNo, DWORD uBaudRate);
extern "C" __declspec(dllimport) void Disconnect(void);

//HerkuleX Communication Initialize// -> Initial call only once(Minimum call Interval 10ms)
extern "C" __declspec(dllimport) BOOL OnInitialize(unsigned int m_imotor_ID);

//HerkulexX  Error Clear Command//
extern "C" __declspec(dllimport) BOOL Herkulex_ErrorClear(unsigned char cID);

//HerkulexX  Servo Command// -> 0: TORQUE_OFF,  1: TORQUE_ON,  2: BRAKE_ON
extern "C" __declspec(dllimport) BOOL Herkulex_Servo_Enable(unsigned char cID, unsigned int uiMode);
/************************************************************************************************************************************************************/

/************************************************************************************************************************************************************/
//RAM & EEP Register Read Set Command//
extern "C" __declspec(dllimport) BOOL SET_RAM_RegisterData_Read(unsigned int m_imotor_ID, unsigned int iAddr, unsigned char count);
extern "C" __declspec(dllimport) BOOL SET_EEP_RegisterData_Read(unsigned int m_imotor_ID, unsigned int iAddr, unsigned char count);
//RAM & EEP Register Write Set Command//
extern "C" __declspec(dllimport) void SET_RAM_RegisterData_Write(unsigned int m_imotor_ID, unsigned int iAddr, unsigned int cData);
extern "C" __declspec(dllimport) void SET_EEP_RegisterData_Write(unsigned int m_imotor_ID, unsigned int iAddr, unsigned int cData);
/************************************************************************************************************************************************************/

/************************************************************************************************************************************************************/
//RAM MAP  Get Data Command
extern "C" __declspec(dllimport) unsigned int GET_RAM_MAP_Read(unsigned int iID, unsigned int iAddr);
//EEP MAP Get Data Command
extern "C" __declspec(dllimport) unsigned int GET_EEP_MAP_Read(unsigned int iID, unsigned int iAddr);
/************************************************************************************************************************************************************/

/************************************************************************************************************************************************************/
//HerkuleX Set LED Control_Command//
extern "C" __declspec(dllimport) void	 Herkulex_Set_LED(unsigned int iID, bool bGreen, bool bBlue, bool bRed); //03 Model not applicable

// Position & Velocity Move Command//
extern "C" __declspec(dllimport) BOOL Position_Move(unsigned char cID, unsigned int iLED, unsigned int iPlayTime, int iTargetPos, int iJogMode);
extern "C" __declspec(dllimport) BOOL Velocity_Move(unsigned char cID, unsigned int iLED, int iTargetVel, int iJogMode);

//New JOG_Move Commad// --> Only available on New HerkuleX Model
extern "C" __declspec(dllimport) BOOL Position_Move2(unsigned char cID, unsigned int iLED, unsigned int iPlayTime, int iTargetPos, int iJogMode, int iprofile, bool bMulti, int turn);
extern "C" __declspec(dllimport) BOOL Velocity_Move2(unsigned char cID, unsigned int iLED, int iTargetVel, int iJogMode, int iprofile, bool bMulti);
/*
[iJogMode]
	0: S_Jog
	1: I_Jog
	2: MS_Jog -> Only available on New HerkuleX  series
	3: MI_Jog  -> Only available on New HerkuleX  series
*/
/************************************************************************************************************************************************************/

/************************************************************************************************************************************************************/
//#####[!Caution!]: ID must be continuous when using JOG mode####//
//JOG Move
extern "C" __declspec(dllimport) BOOL S_JOG_MOVE(unsigned int iPlayTime, unsigned int iTotal_Axis, CMD_SJog * sjogArr);
extern "C" __declspec(dllimport) BOOL I_JOG_MOVE(unsigned int iTotal_Axis, CMD_IJog * ijogArr);

//New Multi JOG ->Only available on New HerkuleX  series
extern "C" __declspec(dllimport) BOOL MS_JOG_MOVE(unsigned int iPlayTime, unsigned int iTotal_Axis, bool bMulti, int turn, CMD_MSJog * msjogArr);
extern "C" __declspec(dllimport) BOOL MI_JOG_MOVE(unsigned int iTotal_Axis, bool bMulti, int turn, CMD_MIJog * mijogArr);
/************************************************************************************************************************************************************/

/************************************************************************************************************************************************************/
//Rollback 
extern "C" __declspec(dllimport) void FactoryReset(unsigned char cID, int iID_Skip, int iBaudrate_Skip);
//Reboot
extern "C" __declspec(dllimport) void Reboot(unsigned char cID);
/************************************************************************************************************************************************************/

