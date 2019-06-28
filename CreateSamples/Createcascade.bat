@echo off
opencv_traincascade -data ./cascade/trained_data/ -vec ./vec/image.vec -bg nglist.txt -numPos 50 -numNeg 60