package com.example.dateandtimepicker;

import androidx.appcompat.app.AppCompatActivity;

import android.app.TimePickerDialog;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TimePicker;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    TimePickerDialog timePickerDialog;
    EditText editTextTime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editTextTime = findViewById(R.id.editText_Time);
        editTextTime.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick (View view){
                open_TimePickerDialog();
            }


        });
    }

    public void onButtonSelectTimeClick(View view) {
        open_TimePickerDialog();
    }

    private void open_TimePickerDialog(){
        int hourOfDay=23;
        int minute=55;
        boolean is24HourView=true;

        timePickerDialog= new TimePickerDialog(this, android.R.style.Theme_Holo_Light_Dialog, new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker timePicker, int i, int i1) {
                editTextTime.setText(i + ":" + i1);
            }
        },hourOfDay, minute, is24HourView);

        timePickerDialog.getWindow().setBackgroundDrawable(new ColorDrawable(Color.TRANSPARENT));
        timePickerDialog.setTitle("Select a Time");
        timePickerDialog.show();
    }
}
