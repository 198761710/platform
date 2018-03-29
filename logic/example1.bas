DO fan
AV rps
DO fan_open
DO fan_close
DI fan_status
AV fan_ontime
AV fan_offtime
AI tempreture

goto main

if fan_open.invalid then goto end
if fan_close.invalid then goto end
if fan_status.invalid then goto end
if tempreture.invalid then goto end

begin:
	if( tempreture >= 5 ) then goto fanstart else goto fanstop

fanstart:
	if( fan.offtime > 5 ) then fan = 1
	goto main 

fanstop:
	if( fan.ontime > 5 ) then fan = 0
	goto main

main:
	a = a + 1
	b = b + 2
	rps = a / a.ontime
	c = (0.0010 == 0.0009)
	d = a.ontime
	fan_open = a.ontime % 2;
	fan_ontime = fan.ontime
	fan_offtime = fan.offtime + 1
	if (fan.offtime > 4) and (tempreture < 4) then tempreture = (fan.offtime + b.ontime)
	if (fan.ontime > 5) and (tempreture < 6) then fan = 0
end:
