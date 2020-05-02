@echo off
echo ################################################################################
echo ################################# 종료 예약 ####################################
echo ################################################################################
echo.
set hour = 0
set minute = 0
set /p hour=몇 시간 후 종료합니까? : 
set /p minute=몇 분 후 종료합니까? : 
set/a t= %hour%*60*60+%minute%*60
shutdown -s -t %t%
cls
:RUN
echo # %hour%시간 %minute%분 후 자동 종료 됩니다.
echo.
set /p a=예약을 취소하려면 1또는 C(c)를 입력하세요...
cls
if %a% == 1 goto OK
if %a% == c goto OK
if %a% == C goto OK
goto RUN
:OK
shutdown -a
echo 예약이 취소되었습니다.
echo.
pause
