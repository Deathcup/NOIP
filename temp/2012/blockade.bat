@echo off
if "%1"=="" goto loop
copy blockade%1.in blockade.in >nul
echo Problem Test
echo Data %1
time<enter
blockade.exe
time<enter
fc blockade.out blockade%1.ans
del blockade.in
del blockade.ans
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
