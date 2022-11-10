package dconeybe.jnidemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

import dconeybe.jnidemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

  // Used to load the 'jnidemo' library on application startup.
  static {
    System.loadLibrary("jnidemo");
  }

  private ActivityMainBinding binding;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);

    binding = ActivityMainBinding.inflate(getLayoutInflater());
    setContentView(binding.getRoot());

        // Example of a call to a native method
    TextView tv = binding.sampleText;

    Log.i("zzyzx", "GOT HERE");
    try {
      ArrayList<Integer> list = new ArrayList<>();
      populateList(list, 5);
      tv.setText(list.toString());
    } catch (Exception e) {
      tv.setText(e.toString());
    }
  }

  public static native void populateList(
      List<Integer> list,
      int count
  );


  public static native long add(int num1, long num2);

  /**
   * A native method that is implemented by the 'jnidemo' native library,
   * which is packaged with this application.
   */
  public native String stringFromJNI();
}