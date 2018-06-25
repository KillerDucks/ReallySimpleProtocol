# ReallySimpleProtocol

Just a simple protocol to transfer data over sockets, more of a C++ learning project.

## Getting Started

Clone the repo and open the solution file up in Visual Studios.

### Prerequisites

Will only work on the Windows platfrom as it uses WinSocks

```
Lastest Windows SDK from Visual Studios Installer
```

### Installing

Build the solution from inside of Visual Studios, or use MSBuild (unsure of the parameters)

```
You may have to Retarget the project/solution if there is a newer version of the Windows SDK.
```

To use the DLL in your project copy the compiled DLL from the Release/Debug folder into your working directory, you will also have to copy the associated header files which are 
located in the project folders ("Packet.h", "Log.h"), if you are using Visual Studios in your project add the DLL as a reference and add the folder of the copyed header to the additional 
directorys or put them in the root folder of your project.

However there are already coded examples of a server and client they should all be in the Release/Debug folder after you build the solution.

```
<DriveLetter>:\<Path to cloned repo>\Debug
<DriveLetter>:\<Path to cloned repo>\Release
```

The following files are the ones you need

```
SampleClient.exe
SampleServer.exe
ReallySimpleProtocol.dll
```

## Running the tests

Currently no tests have been written, you can do a pull request if you would like to add them (I will get around to it soon).

## Deployment

(Will be populated soon :) )

## Built With

* No external dependencies currently (Execpt the Windows SDK)

## Contributing

Create a request and I check it and merge it if its all good.

## License

This project is licensed under the MIT License.
