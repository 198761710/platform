DO fan
AV rps
AV fan_ontime
AV fan_offtime
AI tempreture

if fan_open.invalid then goto End
if fan_close.invalid then goto End
if fan_status.invalid then goto End
if tempreture.invlid then goto End

Begin:
	if( tempreture >= 5 ) then goto FanStart else goto FanStop

FanStart:
	if( fan.offtime > 5 ) then fan = 1
	goto Normal

FanStop:
	if( fan.ontime > 5 ) then fan = 0
	goto Normal

Normal:
	a = a + 1
	A = A + 2
	rps = a / a.ontime
	c = (0.001 == 0.0009)
	fan_ontime = fan.ontime
	fan_offtime = fan.offtime
	if(fan.offtime > 4 and tempreture < 4) then tempreture = fan.offtime 
	if( fan.ontime > 5 and tempreture < 6) then fan = 0

EndPoint:
