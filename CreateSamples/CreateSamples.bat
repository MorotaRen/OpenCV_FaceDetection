@echo off
opencv_createsamples -img ./pos/Face.jpg -vec ./vec/image.vec -num 200 -bgcolor 255 -maxidev 40 -maxxangle 0.8 -maxyangle 0.8 -maxzangle 0.5 -show