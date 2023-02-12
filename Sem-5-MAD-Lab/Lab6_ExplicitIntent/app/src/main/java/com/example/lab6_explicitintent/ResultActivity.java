package com.example.lab6_explicitintent;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class ResultActivity extends AppCompatActivity {
    public static String Operation;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.result);
        TextView result = (TextView)findViewById(R.id.textView3);
        Intent intent = getIntent();
        String addition = (String)intent.getSerializableExtra(Operation);
        result.setText(addition);
    }
}