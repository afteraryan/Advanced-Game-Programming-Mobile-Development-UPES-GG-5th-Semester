package com.example.lab2;

import androidx.appcompat.app.AppCompatActivity;
import android.widget.TextView;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Button button;


    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button = (Button) findViewById(R.id.MainButton);
        button.setOnClickListener(new View.OnClickListener()
          {

              @Override
              public void onClick(View v)
              {
                  Toast.makeText(MainActivity.this, "You'll regret it", Toast.LENGTH_SHORT).show();

              }
          }


        );
    }}