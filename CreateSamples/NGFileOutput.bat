del nglist.txt

cd ./neg

setlocal ENABLEDELAYEDEXPANSION

for %%f in (*.png) do (
set filename=%%f
set ps=neg/
set FilePs=!ps!!filename!
echo !fileps!  >> ../nglist.txt
)
endlocal
