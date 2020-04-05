# Test file for "Lab2_introToAVR"
# Exercise 4


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below
test "PINA: 20, PINB: 50, PINC: 70, PORTD[7:2]: 8, PORTD[1:0]: 00"
setPINA 20
setPINB 50
setPINC 70
continue 2
expectPORTD 0x20
checkResult

test "PINA: 255, PINB: 255, PINC: 255, PORTD[7:2]: 47, PORTD[1:0]: 01"
setPINA 255
setPINB 255
setPINC 255
continue 2
expectPORTD 0xBD
checkResult

test "PINA: 110, PINB: 10, PINC: 10, PORTD[7:2]: 32, PORTD[1:0]: 10"
setPINA 110
setPINB 10
setPINC 10
continue 2
expectPORTD 0x22
checkResult

test "PINA: 10, PINB: 10, PINC: 110, PORTD[7:2]: 32, PORTD[1:0]: 10"
setPINA 10
setPINB 10
setPINC 110
continue 2
expectPORTD 0x22
checkResult

test "PINA: 110, PINB: 90, PINC: 10, PORTD[7:2]: 13, PORTD[1:0]: 11"
setPINA 110
setPINB 90
setPINC 10
continue 2
expectPORTD 0x37
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
