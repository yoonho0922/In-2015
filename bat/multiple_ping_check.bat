@echo off
mkdir 전체결과
cls
echo ################################################################################
echo #################################통신 확인기######################################
echo ################################################################################
echo.
set /p a=PING 네트워크 ID : 
set /p b=PING 시작 호스트 ID : 
set /p c=PING 마지막 호스트 ID : 
cls
echo %a%.%b%~%a%.%c% 통신중...
set e=바이트=32
for /l %%i in (%b%,1,%c%) do (
	ping /n 1 %a%.%%i >> ".\전체결과\통신확인%a%.%%i.txt"
		for /F "tokens=3 delims= " %%p in (전체결과\통신확인%a%.%%i.txt) do (
		if %%p==%e% echo %a%.%%i 통신 성공 >> 통신되는ip.txt
		if %%p==%e% echo. >> 통신되는ip.txt
	)
)
echo.
echo 통신완료
pause