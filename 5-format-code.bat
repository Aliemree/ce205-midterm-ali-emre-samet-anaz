@echo off
@setlocal enableextensions
@cd /d "%~dp0"

echo Formatting Code with Astyle...

astyle --options="astyle-options.txt" --recursive --exclude="src\tests\googletest" "*.h" "*.cpp"

pause