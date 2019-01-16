@echo off
if "%1"=="" goto loop
copy catchcow%1.in catchcow.in >nul
echo Problem Test
echo Data %1
time<enter
catchcow
time<enter
fc catchcow.out catchcow%1.out
del catchcow.in
del catchcow.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13) do call %0 %%i
:end
