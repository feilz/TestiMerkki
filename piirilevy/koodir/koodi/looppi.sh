for ((;;))
do
avrdude -c avrisp -p t861 -P /dev/ttyUSB0 -b 19200 -U flash:w:a.out
done
