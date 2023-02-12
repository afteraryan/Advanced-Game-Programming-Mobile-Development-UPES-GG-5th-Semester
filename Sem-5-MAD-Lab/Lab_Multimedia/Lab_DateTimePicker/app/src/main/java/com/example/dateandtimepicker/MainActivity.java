import android.graphics.Camera;
import android.media.MediaRecorder;
import android.os.Bundle;
import android.view.SurfaceView;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;

import com.example.dateandtimepicker.R;

public class MainActivity extends AppCompatActivity {

    private SurfaceView mSurfaceView;
    private Button mButton;

    private Camera mCamera;
    private MediaRecorder mMediaRecorder;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mSurfaceView = findViewById(R.id.surface_view);
        mButton = findViewById(R.id.button);

        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (mMediaRecorder == null) {
                    startRecording();
                } else {
                    stopRecording();
                }
            }
        });
    }

    @Override
    protected void onResume() {
        super.onResume();
        startCamera();
    }

    @Override
    protected void onPause() {
        super.onPause();
        stopCamera();
    }

    private void startCamera() {
        if (mCamera == null) {
            mCamera = Camera.open();
            mCamera.setDisplayOrientation(90);
            mCamera.setPreviewDisplay(mSurfaceView.getHolder());
            mCamera.startPreview();
        }
    }

    private void stopCamera() {
        if (mCamera != null) {
            mCamera.stopPreview();
            mCamera.release();
            mCamera = null;
        }
    }

    private void startRecording() {
        try {
            mMediaRecorder = new MediaRecorder();
            mMediaRecorder.setCamera(mCamera);
            mMediaRecorder.setAudioSource(MediaRecorder.AudioSource.CAMCORDER);
            mMediaRecorder.setVideoSource(MediaRecorder.VideoSource.CAMERA);
            mMediaRecorder.setOutputFormat(MediaRecorder.OutputFormat.MPEG_4);
            mMediaRecorder.setAudioEncoder(MediaRecorder.AudioEncoder.AMR_NB);
            mMediaRecorder.setVideoEncoder(MediaRecorder.VideoEncoder.H264);
            mMediaRecorder.setVideo
