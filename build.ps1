if (-not (Get-Command cmake.exe -ErrorAction SilentlyContinue).Path) {
    Write-Host "    ##################################"
    Write-Host "    #     CMake is not installed.    #"
    Write-Host "    ##################################"
    $choice = Read-Host "    Do you want to install it? [Y/n]"    
    if ($choice -ne 'N' -or $choice -ne 'n') {
        if (Get-Command winget -ErrorAction SilentlyContinue) {
            Write-Host "Installing CMake..."
            winget install cmake
        }
        elseif (Get-Command choco -ErrorAction SilentlyContinue) {
            Write-Host "Installing CMake..."
            choco install cmake -y
        }
        else {
            Write-Host "    Unsupported package manager. Please install CMake manually."
            Write-Host "    Before running this program, make sure CMake is installed on your machine."
            exit 1
        }
        Write-Host "CMake has been installed."
    }
    else {
        Write-Host "    Before running this program, make sure CMake is installed on your machine."
        exit 1
    }
}

if (Test-Path -Path ".\Build" -PathType Container) {
    Write-Host "'Build' folder is already present!"
    
    $choice = Read-Host "Do you want to delete it? [Y/n]"
    if ($choice -ne 'N' -or $choice -ne 'n') {
        Write-Host "Deleting existing 'Build' folder..."
        Remove-Item -Path ".\Build" -Recurse -Force
    } else {
        exit 1
    }
}


mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
cd ..
cp Automated-Job-Allocator.csv bin/
.\bin\Automated-Job-Allocator.exe
