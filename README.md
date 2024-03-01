# Educational DPC Bugcheck Driver

## Warning

This driver is for educational purposes only and demonstrates the use of DPC in Windows kernel drivers. **When loaded, this driver will intentionally cause a system crash with the Bug Check 0xB8 (ATTEMPTED_SWITCH_FROM_DPC).** This is to illustrate what happens when a wait operation, attach process, or yield is attempted from a DPC routine, which is an illegal operation in the Windows kernel.

## Description

The `DPCBugcheckDriver` is designed to demonstrate the improper use of DPC routines that leads to a system crash. Upon loading, the driver initializes a DPC and inserts it into the system's DPC queue. The DPC routine then attempts an illegal operation by calling `KeDelayExecutionThread`, a wait operation, causing the system to crash with a Bug Check code of 0xB8 (ATTEMPTED_SWITCH_FROM_DPC). https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/bug-check-0xb8--attempted-switch-from-dpc

## Installation

This driver is for educational purposes and should only be used in a safe, controlled environment, such as a virtual machine or a test system that does not contain sensitive data. 

To install this driver:

1. Compile the driver using the Windows Driver Kit (WDK).
2. Use the service control manager to install and start the driver.

## Usage

After the driver is successfully loaded, it will automatically execute the DPC routine and cause a system crash with the bug check code 0xB8.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Disclaimer

This software is provided "as is", without warranty of any kind, express or implied. Use it at your own risk. The author or contributors cannot be held responsible for any damage or loss of data resulting from its use. Again, **this driver is intended for educational purposes only** and should not be used in production environments or on any system with data you cannot afford to lose.

