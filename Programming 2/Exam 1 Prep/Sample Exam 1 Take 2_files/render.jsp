
Event.observe(document,"dom:loaded", function() {
  $$('a[href*="playMedia.jsp"]').invoke('observe', 'click', openLTI);
});

function openLTI(event) {
  var ok = false;
  var resp;
  var url = this.href;
  var query = '';
  var p = url.indexOf('?');
  if (p >= 0) {
    query = url.substr(p);
  }
	var dimensions = document.viewport.getDimensions();
	var width = Math.round(dimensions.width * 0.8);
	var height = Math.round(dimensions.height * 0.8);
	var el_if = document.getElementById('HelixMedia-overlay');
	var osc_lbParam = {
		defaultDimensions : { w : width, h : height },
		title : '',
		openLink : el_if,
		contents : '<iframe src="' + url + '" width="100%" height="100%" allowfullscreen />',
		closeOnBodyClick : false,
		showCloseLink : true,
		useDefaultDimensionsAsMinimumSize : true,
		ajax: false
	};
	var osc_lightbox = new lightbox.Lightbox(osc_lbParam);
	osc_lightbox.open();
	event.stop();
}
