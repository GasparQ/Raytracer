package allindevelopment.com.accelerometre;

import android.app.Activity;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class MainActivity extends Activity implements SensorEventListener {

    private ImageView mPointerLeft;
    private ImageView mPointerRight;
    private SensorManager mSensorManager;
    private Sensor mAccelerometer;
    private Sensor mMagnetometer;
    public TextView acc;
    public TextView magn;
    int axeZ = 0;
    int axeY = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mSensorManager = (SensorManager)getSystemService(SENSOR_SERVICE);
        mMagnetometer = mSensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
        mPointerLeft = (ImageView) findViewById(R.id.left);
        mPointerRight = (ImageView) findViewById(R.id.right);
        View decorView = getWindow().getDecorView();
        int uiOptions = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_FULLSCREEN;
        decorView.setSystemUiVisibility(uiOptions);
    }

    protected void onResume() {
        super.onResume();
        mSensorManager.registerListener(this, mMagnetometer, SensorManager.SENSOR_DELAY_FASTEST);
    }

    protected void onPause() {
        super.onPause();
        mSensorManager.unregisterListener(this, mMagnetometer);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {

        if ((Math.round(event.values[2]) * 15 >= axeZ + 15) || (Math.round(event.values[2]) * 15 <= axeZ - 15)) {
            axeZ = Math.round(event.values[2]) * 15;
            RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(mPointerLeft.getLayoutParams());
            RelativeLayout.LayoutParams params2 = new RelativeLayout.LayoutParams(mPointerRight.getLayoutParams());
            params.setMargins(-axeY, axeZ, 0, 0);
            params2.setMargins(900 - axeY, axeZ, 0, 0);
            mPointerLeft.setLayoutParams(params);
            mPointerRight.setLayoutParams(params2);
        }

        if ((Math.round(event.values[1]) * 15 >= axeY + 15) || (Math.round(event.values[1]) * 15 <= axeY - 15)) {
            axeY =  Math.round(event.values[1]) * 15;
            RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(mPointerLeft.getLayoutParams());
            RelativeLayout.LayoutParams params2 = new RelativeLayout.LayoutParams(mPointerRight.getLayoutParams());
            params.setMargins(-axeY, axeZ, 0, 0);
            params2.setMargins(900 - axeY, axeZ, 0, 0);
            mPointerLeft.setLayoutParams(params);
            mPointerRight.setLayoutParams(params2);
        }


/*        RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT);
        params.setMargins(100, 100 + (int)event.values[2], 200, 200);
        mPointer.setLayoutParams(params);
        System.out.println("EGAL = "+ (int)event.values[2]);*/
        //magn.setText("MAGNETIC  : X = " + event.values[0] + "  Y = " + event.values[1] + "  Z = " + event.values[2]);
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
        // TODO Auto-generated method stub

    }

}

