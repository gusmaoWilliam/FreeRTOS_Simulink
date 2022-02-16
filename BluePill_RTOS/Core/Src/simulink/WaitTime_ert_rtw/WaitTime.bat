set MATLAB=D:\Program Files\Polyspace\R2020a


call  "\\DESKTOP-LTEBEMH\D$\Program Files\Polyspace\R2020a\bin\win64\checkMATLABRootForDriveMap.exe" "\\DESKTOP-LTEBEMH\D$\Program Files\Polyspace\R2020a"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n
cd .

chcp 1252

if "%1"=="" ("D:\Program Files\Polyspace\R2020a\bin\win64\gmake" MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f WaitTime.mk all) else ("D:\Program Files\Polyspace\R2020a\bin\win64\gmake" MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  -f WaitTime.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
