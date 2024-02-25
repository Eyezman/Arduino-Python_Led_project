#pip install pyserial
import serial.tools.list_ports



ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
portsList = []

for instance in ports:
    portsList.append(str(instance))
    print(str(instance))


Com_selection = input("Please select the Com port you want to enable #: ")

for com_item in range(len(portsList)):
    if portsList[com_item].startswith("COM" + str(Com_selection)):
        selected_com = "COM" + str(Com_selection)

serialInst.baudrate = 9600
serialInst.port = selected_com
serialInst.open()


while True:
    command = input("What function you want arduino to perform?(super/on/off/exit): ")
    serialInst.write(command.encode('utf-8'))

    if command == 'exit':
        exit()