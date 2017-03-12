/*
 * (c) 2016 Ruslan Mikhno
 * http://www.mikhno.org - web development, php, javascript, html, css, etc.
 *
 * Access Control for 44\223 online.
 *
 * access-control.js: Main access control script.
 */
$(document).ready(function() {
    console.log( "AC: Ready!" );
	var groupId = $('#access-control-group').html();
	var userId = $('#access-control-id').html();
	var userCounter = $('#access-control-counter').text();
	console.log( "AC: Group:" + groupId + "!" );
	console.log( "AC: ID:" + userId + "!" );

	$('td.vodd').children('a').each(function () {
		if (this.text == "Регистрация")
			this.text = "Демо-доступ";
	});

	// Testing cond:
	/*var ip = $('#access-control-ip').html();
	if ((ip != "178.71.185.186")
		&& (ip != "176.100.40.234"))
		return;*/
	console.log( "AC: ip check ok");
	// End of Testing cond.

	var access = true;
	var reason = "All is ok!";
	if (groupId == 0) {
		access = false;
		reason = "Guest";
	}

	if (access)
		return;
	console.log( "AC: Access denied, reason: '" + reason + "'." );

	var pathname = window.location.pathname;
	if ((pathname.includes('subscribe'))
		|| (pathname.includes('oplata_podpiski'))
		|| (pathname.includes('demo-subckribe'))
		|| (pathname.includes('terms-of-service'))
		|| (pathname.includes('kalkulator_nmsk'))
		|| (pathname.includes('mir'))		
		|| (pathname.includes('index/0-40'))
		|| (pathname.includes('index/0-3'))
		|| (pathname.includes('index/3')))
		return; // Ignore this.

	// Block access:


	// Create cookie.
	var createCookie = function(name, value, days) {
		var expires;
		if (days) {
			var date = new Date();
			date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
			expires = "; expires=" + date.toGMTString();
		}
		else {
			expires = "";
		}
		document.cookie = name + "=" + value + expires + "; path=/";
	}

	// Read cookie.
	function getCookie(c_name) {
		if (document.cookie.length > 0) {
			c_start = document.cookie.indexOf(c_name + "=");
			if (c_start != -1) {
				c_start = c_start + c_name.length + 1;
				c_end = document.cookie.indexOf(";", c_start);
				if (c_end == -1) {
					c_end = document.cookie.length;
				}
				return unescape(document.cookie.substring(c_start, c_end));
			}
		}
		return "";
	}


	// Show modal:
	function accessBlockula() {
		createCookie("access-denied-show", "true", 7);

		/*
		*/
		var contentHTML = '<div id="access-blockula">'
						+'<style>'
						+'.vex-content {'
						+'background-image: url(http://44-online.ru/images/logo-transparent.png) !important;'
						+'background-repeat: no-repeat !important;;'
						+'background-position: 10px 10px !important;;'
						+'background-size: auto 180px !important;;'
						+'}'
						+'.access-blockula-description {'
						+'    margin-left: 125px;'
						+'    margin-top: -30px;'
						+'    padding-bottom: 15px;'
						+''
						+'}'
						+'.access-blockula-counter {'
						+'    display: block;'
						+'    padding: 15px;'
						+'    margin: 25px 0 0;'
						+'    /*background: #ebebeb;*/'
						+'    /*color: #2C5497;*/'
						+'    /*font: bold 24px Tahoma, Verdana, Segoe, sans-serif;*/'
						+'    text-decoration: none;'
						+'    text-align: center;'
						+'}'
						+'a.access-blockula-btn {'
						+'    display: block;'
						+'    padding: 15px;'
						+'    margin: 25px 200px 0;'
						+'    background: #2C5497;'
						+'    color: #fff;'
						+'    font: bold 18px Tahoma, Verdana, Segoe, sans-serif;'
						+'    text-decoration: none;'
						+'    text-align: center;'
						+'}'
						+'a:hover.access-blockula-btn,'
						+'a:active.access-blockula-btn,'
						+'a:focus.access-blockula-btn {'
						+'    background: #ff9800;'
						+'}'
						+'.xw-plain .xw-ml, .xw-plain .xw-tl, .xw-plain .xw-bl {'
						+'    background-color: #fbfbfb;'
						+'}'
						+'.xw-hdr .xw-hdr-text,'
						+'.myWinCont, .myWinCont td, .myWinCont dl, .myWinCont dt,'
						+'.xw-plain .myBtnCenter a:link, .xw-plain .myBtnCenter a:visited {'
						+'    color: #000;'
						+'}'
						+'.xw-plain .myBtnLeft, .xw-plain .downBtn .myBtnLeft, .xw-plain .myBtnCenter, .xw-plain .downBtn .myBtnCenter, .xw-plain .myBtnRight, .xw-plain .downBtn .myBtnRight {'
						+'    background-color: #ccc;'
						+'    border-color: #ccc;'
						+'}'
						+'.myWinCont input[type="text"], .myWinCont input[type="password"], .myWinCont .tmplCodeH {'
						+'    color: #000;'
						+'    border: 2px solid #54565a;'
						+'    background-color: #fff;'
						+'}'
						+'</style>'
						+'<div class="access-blockula-description">'
						+'<p>Вы на стартовой странице Информационно-аналитического портала по контрактной системе 44-online. Портал работает с 2013 года. Все программы и ресурсы портала работают онлайн по единой подписке. Справки: <a href="mailto:zakaz@44-online.ru">zakaz@44-online.ru</a></p>'
						+'</div>'
						+'<hr />'
						+'<a href="http://www.44-online.ru/subscribe" class="access-blockula-btn">Подписка</a>'
						+'<a href="http://www.44-online.ru/demo-subckribe" class="access-blockula-btn">Демо – доступ</a>'
						+'<a href="javascript://" onclick="new _uWnd(\'LF\',\' \',-250,-110,{autosize:0,closeonesc:1,resize:1},{url:\'/index/40\'});return false;" rel="nofollow" class="access-blockula-btn">Вход для подписчиков</a>'
						+'<div class="access-blockula-counter">Подписались <span id="access-blockula-usercount" style="border: 3px solid #444;border-radius: 5px;padding: 3px;    margin: 5px;">'+userCounter+'</span></div>'
						+'<hr />'
					+'</div>';

		var options = {
				content: contentHTML,
				showCloseButton: false,
				escapeButtonCloses: false,
				overlayClosesOnClick: false,
				appendLocation: 'body',
				css: {},
				overlayClassName: '',
				overlayCSS: {},
				contentClassName: '',
				contentCSS: {"width": "800px"},
				closeClassName: '',
				closeCSS: {}
			  };
		vex.open(options);
	}

  $.ajax({
    url : "http://2055.su/ucoz_registration/access-check.php",
    success : function(result){
    if (result == "1") {
      // Access is open for all.
    } else {
      // Wait 5 min and\or show modal:
    	var accessDeniedShow = getCookie("access-denied-show");
    	if (accessDeniedShow != "true") {
    		setTimeout(function(){
    			accessBlockula();
    		}, 60000);
    	} else
    		accessBlockula();
    }
  }});
});
