import serial
import uinput

ser    = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
events = (
	uinput.KEY_W,
	uinput.KEY_A,
	uinput.KEY_S,
	uinput.KEY_D
)
device = uinput.Device(events)

if ser.isOpen():
	ser.close()
	ser.open()
	ser.write("T")

def main():
	while ser.isOpen():
		line = ser.readline()
		buttons(line)

	ser.close()

def buttons(line):
	print line
	buttons = line.split(' ');

	if len(buttons) > 10:

		button_DU = bool(int(buttons[0]))
		button_DD = bool(int(buttons[1]))
		button_DL = bool(int(buttons[2]))
		button_DR = bool(int(buttons[3]))
		button_Start = bool(int(buttons[4]))
		button_A = bool(int(buttons[5]))
		button_B = bool(int(buttons[6]))
		button_Z = bool(int(buttons[7]))
		button_L = bool(int(buttons[8]))
		button_R = bool(int(buttons[9]))
		button_CU = bool(int(buttons[10]))
		button_CD = bool(int(buttons[11]))
		button_CL = bool(int(buttons[12]))
		button_CR = bool(int(buttons[13]))

		if button_DU:
			device.emit_click(uinput.KEY_W)

		if button_DD:
			device.emit_click(uinput.KEY_S)

		if button_DL:
			device.emit_click(uinput.KEY_A)

		if button_DR:
			device.emit_click(uinput.KEY_D)


if __name__ == "__main__":
	main()
