package com.example.lab4_activitylifecycle;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.*;

public class MainActivity extends AppCompatActivity {

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toast.makeText(MainActivity.this,"onCreate was Called",Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onStart() {
        super.onStart();
        Toast.makeText(MainActivity.this,"onStart was Called",Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onPause() {
        super.onPause();
        Toast.makeText(MainActivity.this,"onPause was Called",Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onStop() {
        super.onStop();
        Toast.makeText(MainActivity.this,"onStop was Called",Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Toast.makeText(MainActivity.this,"onDestroy was Called",Toast.LENGTH_SHORT).show();
    }

    @Override

    public void onRestart() {
        super.onRestart();
        Toast.makeText(MainActivity.this,"onRestart was Called",Toast.LENGTH_SHORT).show();
    }
    @Override
    public void onResume() {
        super.onResume();
        Toast.makeText(MainActivity.this,"onResume was Called",Toast.LENGTH_SHORT).show();
    }
}
