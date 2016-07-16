@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=CTC_dec_p_mex
set MEX_NAME=CTC_dec_p_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for CTC_dec_p > CTC_dec_p_mex.mki
echo COMPILER=%COMPILER%>> CTC_dec_p_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> CTC_dec_p_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> CTC_dec_p_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> CTC_dec_p_mex.mki
echo LINKER=%LINKER%>> CTC_dec_p_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> CTC_dec_p_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> CTC_dec_p_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> CTC_dec_p_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> CTC_dec_p_mex.mki
echo BORLAND=%BORLAND%>> CTC_dec_p_mex.mki
echo OMPFLAGS= >> CTC_dec_p_mex.mki
echo OMPLINKFLAGS= >> CTC_dec_p_mex.mki
echo EMC_COMPILER=mingw64>> CTC_dec_p_mex.mki
echo EMC_CONFIG=optim>> CTC_dec_p_mex.mki
"C:\Program Files\MATLAB\R2015b\bin\win64\gmake" -B -f CTC_dec_p_mex.mk
