import 'package:flutter/material.dart';
import 'package:flutter_icons/flutter_icons.dart';
import 'package:get_it/get_it.dart';

import './bt.dart';
import './connect.dart';
import './settings.dart';

GetIt getIt = GetIt.instance;

const ICON_SIZE = 24.0;
void main() {
  getIt.registerSingleton<ConfigNameController>(ConfigNameController("ESP32"));
  getIt.registerSingleton<SnackbarController>(SnackbarController());
  getIt.registerSingleton<BluetoothController>(BluetoothController());
  runApp(Bike());
}

class Bike extends StatelessWidget {
  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        // This makes the visual density adapt to the platform that you run
        // the app on. For desktop platforms, the controls will be smaller and
        // closer together (more dense) than on mobile platforms.
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      // home: HomePage(title: 'Flutter Demo Home Page'),
      home: App(),
    );
  }
}

class HomePage extends StatefulWidget {
  HomePage({Key key, this.title}) : super(key: key);

  final String title;

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      _counter++;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: <Widget>[
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: <Widget>[
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Start',
                  icon: Icon(FontAwesome.bolt),
                  iconSize: ICON_SIZE,
                ),
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Shut off',
                  icon: Icon(FontAwesome.power_off),
                  iconSize: ICON_SIZE,
                ),
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Lock',
                  icon: Icon(FontAwesome.lock),
                  iconSize: ICON_SIZE,
                ),
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Unlock',
                  icon: Icon(FontAwesome.unlock),
                  iconSize: ICON_SIZE,
                ),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: <Widget>[
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Left turn',
                  icon: Icon(FontAwesome.arrow_left),
                  iconSize: ICON_SIZE,
                ),
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Hazard',
                  icon: ImageIcon(new AssetImage('assets/icon_hazard.png')),
                  iconSize: ICON_SIZE,
                ),
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Right turn',
                  icon: Icon(FontAwesome.arrow_right),
                  iconSize: ICON_SIZE,
                ),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: <Widget>[
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Marker Lights',
                  icon: ImageIcon(new AssetImage('assets/icon_light.png')),
                  iconSize: ICON_SIZE,
                ),
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Headlight',
                  icon: ImageIcon(new AssetImage('assets/icon_low-beam.png')),
                  iconSize: ICON_SIZE,
                ),
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'High Beam',
                  icon: ImageIcon(new AssetImage('assets/icon_high-beam.png')),
                  iconSize: ICON_SIZE,
                ),
              ],
            ),
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: <Widget>[
                IconButton(
                  onPressed: _incrementCounter,
                  tooltip: 'Horn',
                  icon: Icon(FontAwesome.bullhorn),
                  iconSize: ICON_SIZE,
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
class App extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).primaryColor,
        title: Text("ESP32 Controller"),
        actions: <Widget>[
          IconButton(
            icon: Icon(Icons.settings),
            onPressed: () {
              showDialog(
                context: context,
                builder: (BuildContext context) {
                  return AlertDialog(
                    content: SettingsButton(),
                  );
                },
              );
            },
          ),
          BluetoothConnect(
            deviceName: "ESP32",
          ),
        ],
      ),
      body: AppHomeScreen(),
    );
  }
}

class AppHomeScreen extends StatefulWidget {
  @override
  createState() => _AppHomeScreenState();
}

class _AppHomeScreenState extends State<AppHomeScreen> {
  final bluetooth = getIt.get<BluetoothController>();

  double _slider = 0.5;
  bool _pressed = false;

  void changeSlider(double value) {
    bluetooth.sendValue((_slider * 100).toInt());
    setState(() {
      _slider = value;
    });
  }

  @override
  Widget build(BuildContext context) {
    Color primary = Theme.of(context).primaryColor;
    TextStyle headline = DefaultTextStyle.of(context)
        .style
        .apply(fontSizeFactor: 2.0, color: primary);

    return Padding(
      padding: EdgeInsets.all(20),
      child: Column(
        children: <Widget>[
          Container(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.stretch,
              children: <Widget>[
                Text(
                  "Input",
                  textAlign: TextAlign.left,
                  style: headline,
                ),
                SizedBox(height: 10),
               
                SizedBox(height: 10),
                Slider(
                  value: _slider,
                  onChangeStart: changeSlider,
                  onChanged: changeSlider,
                  onChangeEnd: changeSlider,
                ),
                SizedBox(height: 10),
                
              ],
            ),
          ),
          SizedBox(height: 20),
          Divider(
            color: primary,
          ),
          SizedBox(height: 20),
          // Container(
          //   child: Column(
          //     crossAxisAlignment: CrossAxisAlignment.stretch,
          //     children: <Widget>[
          //       Text(
          //         "Output",
          //         textAlign: TextAlign.left,
          //         style: headline,
          //       ),
          //       SizedBox(height: 10),
          //       StreamBuilder<String>(
          //         initialData: "No Data arrived",
          //         stream: bluetooth.getStringStream(),
          //         builder: (context, snapshot) {
          //           // print(snapshot.data);
          //           return Text(snapshot.data);
          //         },
          //       ),
          //       StreamBuilder<bool>(
          //         initialData: false,
          //         stream: bluetooth.getBoolStream(),
          //         builder: (context, snapshot) {
          //           // print(snapshot.data);
          //           return Text(snapshot.data.toString());
          //         },
          //       ),
          //       StreamBuilder<int>(
          //         initialData: 0,
          //         stream: bluetooth.getIntStream(),
          //         builder: (context, snapshot) {
          //           // print(snapshot.data);
          //           return Text(snapshot.data.toString());
          //         },
          //       ),
          //     ],
          //   ),
          // ),
        ],
      ),
    );
  }
}