package com.atanakov.shapecomposer

import android.content.Context
import android.graphics.Canvas
import android.graphics.Paint
import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.v7.app.AppCompatActivity;
import android.view.Menu
import android.view.MenuItem
import android.view.View

import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    inner class Canvass (context: Context): View(context) {

        override fun onDraw (canvas: Canvas) {
            canvas.drawRGB (255, 255, 255)
            val width = getWidth ()
            val hieght = getHeight ()
            val brush1 = Paint ()
            brush1.setARGB (255, 255, 0, 0)
            brush1.setStyle (Paint.Style.STROKE)
            for (f in 0..9)
                canvas.drawCircle ((width / 2) .toFloat (), (hieght / 2) .toFloat (), (f * 15) .toFloat (), brush1)
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        setSupportActionBar(toolbar)

        val layout = findViewById (R.id.canvasLayout) as android.support.constraint.ConstraintLayout
        val background = Canvass (this)
        layout.addView (background)

        fab.setOnClickListener { view ->
            Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                .setAction("Action", null).show()
        }
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.menu_main, menu)
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        return when (item.itemId) {
            R.id.action_settings -> true
            else -> super.onOptionsItemSelected(item)
        }
    }
}
