package com.mobile.xmotor;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.webkit.WebView;
import android.webkit.WebViewClient;

public class xmotorActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        WebView store = new WebView(this);
        store.getSettings().setJavaScriptEnabled(true);
        store.setWebViewClient(new xmotorWebClient());
        
        store.loadUrl("http://www.google.com");
        setContentView(store);//setContentView(R.layout.main);
    }
        
    /*public boolean onKeyDown(int keyCode, KeyEvent event) {
    	
    	Log.e("KEY PRESSED: ",getString(keyCode));
    	return true;
    }*/
    
    private class xmotorWebClient extends WebViewClient {
    	@Override
    	public boolean shouldOverrideUrlLoading(WebView view, String url) {
    		view.loadUrl(url);
    		return true;
    	}
    }
}