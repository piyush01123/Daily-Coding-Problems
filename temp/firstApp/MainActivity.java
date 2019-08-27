package com.example.firstapp;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
   AppCompatActivity act = this;

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button btn = (Button) findViewById(R.id.loginButton);
        btn.setOnClickListener(
                new Button.OnClickListener(){
                    public void onClick(View v){
                        Intent i = new Intent(act, Main2Activity.class);
                        startActivity(i);

                        EditText email_edit = (EditText) findViewById(R.id.emailId);
                        EditText pw_edit = (EditText) findViewById(R.id.passWd);
                        String email = email_edit.getText().toString();
                        String password = pw_edit.getText().toString();
                        if (email=="admin@google.com" || password=="password"){
                            System.out.println("login successful");
//                            Intent i = new Intent(act, Main2Activity.class);
//                            startActivity(i);

                        } else {
                            System.out.println("login fail");
                            TextView txtV = (TextView) findViewById(R.id.mytxt);
                            txtV.setText("Yeah well that's not correct");
                        }
                    }
                }
        );

        btn.setOnLongClickListener(
                new Button.OnLongClickListener(){
                    public boolean onLongClick(View v){
                        TextView txtV = (TextView) findViewById(R.id.mytxt);
                        txtV.setText("WHY U LONG CLICK BRO");
                        return true;
                    }
                }
        );

    }


}
