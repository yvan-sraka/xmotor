function WebViewAssistant() {
}

WebViewAssistant.prototype.setup = function() {
	
	this.controller.serviceRequest('palm://com.palm.connectionmanager', {
	    method: 'getstatus',
	    parameters: {
	        subscribe: true},
	    onSuccess: function(result) {
	    	if (result["isInternetConnectionAvailable"]) {
	    		
	    	}
	    	else{
	    		Mojo.Controller.stageController.pushScene({name:"errorWifi"});
	    	}
	}});

this.controller.stageController.setWindowOrientation("free");

this.appMenuModel = {items: [{label:$L("Back to home"),command:"return-home"}]};
this.controller.setupWidget(Mojo.Menu.appMenu,{},this.appMenuModel);

this.controller.setupWidget("spinner",{spinnerSize: Mojo.Widget.spinnerLarge},{spinning: true});

this.controller.setupWidget("WebId",
    this.attributes = {
        url:    'http://www.google.com',
    },
    this.model = {
    }
);

this.controller.listen("WebId",Mojo.Event.webViewLoadStopped,this.loadStopped.bindAsEventListener(this));
};

WebViewAssistant.prototype.handleCommand = function (event){
	if (event.type == Mojo.Event.back){
		event.stop();
		$("WebId").mojo.goBack();
	}
	if (event.type == Mojo.Event.command){
		if (event.command == "return-home"){
			$("WebId").mojo.openURL("http://www.google.com");
		}
	}
}

WebViewAssistant.prototype.loadStopped = function(event){
    this.controller.get("spinner").mojo.stop();
};

WebViewAssistant.prototype.activate = function(event) {
};

WebViewAssistant.prototype.deactivate = function(event) {
};

WebViewAssistant.prototype.cleanup = function(event) {
};
