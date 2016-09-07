# Cognitive-RobotController
A C++ program which interfaces with the Emotiv Epoc SDK to access data from Emotiv Epoc Headset. It also issues serial commands based on the cognitiv input. 

![main](https://cloud.githubusercontent.com/assets/16982827/18298514/c34d0854-74d6-11e6-98ef-3d4e8d1bec09.JPG)

## Case Study Results
The program was tested with the Emotiv Epoc headset. 

![emotiv](https://cloud.githubusercontent.com/assets/16982827/18298653/e68e045c-74d7-11e6-9372-f881055f51a7.png)

However due to restrictions from Emotiv, the headset data could not be directly accessed. The headset connected to the Emotiv EPOC desktop app from which the Emotiv API allowed third party developers to connect to the headset. Using the desktop app, the headset was trained for 5-10 users. However it was difficult to train multiple cognitiv actions per user. (eg:- push command, pull command). The accuracy was significantly low and it was not in a state for end consumer usage.  

## Future Work
Much research is needed in this area and this is one of the first attempts to create cognitive controlled devices. With the improvement of developer tools, SDKs, APIs and machine learning; this would not be a dream in the future.   

## Platform Dependency 

The program runs only in a Windows environment mainly due to the API provided by Emotiv. At the time of development(first iteration), the Emotiv API was not of high quality and it was difficult to setup. 

## License

This package is free and open source software, licensed under GPL. (Check with Emotiv for Licensing regarding their API)
