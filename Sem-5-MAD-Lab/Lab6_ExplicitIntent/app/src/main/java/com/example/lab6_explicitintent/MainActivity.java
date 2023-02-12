package com.example.lab6_explicitintent;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;


public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        final EditText first = (EditText)
                findViewById(R.id.editTextNumber1);
        final EditText second = (EditText)
                findViewById(R.id.editTextNumber2);



        Button add = (Button) findViewById(R.id.btn_Add);
        Button subtract = (Button) findViewById(R.id.btn_Sub);
        Button multiply = (Button) findViewById(R.id.btn_Mul);
        Button divide = (Button) findViewById(R.id.btn_Div);

        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ResultActivity.Operation="sum";
                int num1 = Integer.parseInt(first.getText().toString());
                int num2 = Integer.parseInt(second.getText().toString());
                Intent intent1 = new Intent(MainActivity.this,
                        ResultActivity.class);
                intent1.putExtra("sum", num1+"+"+num2+"="+(num1+num2));
                startActivity(intent1);

            }
        });

        subtract.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ResultActivity.Operation="subtract";
                int num1 = Integer.parseInt(first.getText().toString());
                int num2 = Integer.parseInt(second.getText().toString());
                Intent intent2 = new Intent(MainActivity.this,
                        ResultActivity.class);
                intent2.putExtra("subtract", num1+"-"+num2+"="+(num1-num2));
                startActivity(intent2);

            }
        });
        multiply.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ResultActivity.Operation="multiply";
                int num1 = Integer.parseInt(first.getText().toString());
                int num2 = Integer.parseInt(second.getText().toString());
                Intent intent2 = new Intent(MainActivity.this,
                        ResultActivity.class);
                intent2.putExtra("multiply", num1+"*"+num2+"="+(num1*num2));
                startActivity(intent2);

            }
        });

        divide.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ResultActivity.Operation="divide";
                int num1 = Integer.parseInt(first.getText().toString());
                int num2 = Integer.parseInt(second.getText().toString());
                Intent intent2 = new Intent(MainActivity.this,
                        ResultActivity.class);
                intent2.putExtra("divide", num1+"/"+num2+"="+(num1/num2));
                startActivity(intent2);

            }
        });
    }
}