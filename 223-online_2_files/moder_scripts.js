var _entrRmNew = {};
			var timerId;
			var _entrRemNew = _entrRemNew?_entrRemNew:function _entrRemNew(c, b, a, d, e) {
    			if (!d) {
        			d = "Are you sure?"
    			}
    			if (!_entrRmNew[c] && confirm(d)) {    				
        			_entrRmNew[c] = 1;        			
        			_uPostForm("", {
            			url: b
        			});
					if(!e){
						var parentMarg = $("#"+c).parents('div.u-mpanel');	
						parentMarg.removeClass('open');
						parentMarg.mouseover(function(){
							bind_moder_over(parentMarg);
						});
						parentMarg.mouseleave(function(){
							bind_moder_leave(parentMarg);
						});	
					}
        			$("#"+c).parent('li').remove();
    			}
			}	

			if( !window.uCoz ) window.uCoz = {};
			if( !uCoz.spam ) uCoz.spam = {};

			uCoz.spam.moderPanelNotSpamClickNew = function(elem) {
			var elem = $(elem);
			var messageID = elem.attr('data-message-id');
			var notSpam = elem.attr('data-not-spam') ? 0 : 1;			
			$.post('/index/', {
				a          : 101,
				scope_id   : uCoz.spam.config.scopeID,
				message_id : messageID,
				not_spam   : notSpam
			}).then(function(response) {								
				if( response.error ) {
					alert(response.error);
					return;
				};
				if( response.status == 'admin_message_not_spam' ) {						
					elem.attr('data-not-spam', true);
					$('#del-as-spam-' + messageID).parents('li').addClass('hidden');					
					$('#not-spam-' + messageID).parents('li').addClass('hover');
				} else {					
					elem.removeAttr('data-not-spam');
					$('#del-as-spam-' + messageID).parents('li').removeClass('hidden');
					$('#not-spam-' + messageID).parents('li').removeClass('hover');
				};
				var parent = $('#del-as-spam-' + messageID).parents('.u-mpanel');
				if (parent.hasClass('moder-margin')){
					var dir = parent.hasClass('up-right') ? 'right' : 'left';
					parent.attr("style", "margin-" + dir + ": " + (parseInt($('#del-as-spam-' + messageID).parents('ul.u-mpanel-l').width())+10)+ "px!important;");	
				}				
				console.log(response);
			});
			return false;

		}

		var ban_item_new = ban_item_new?ban_item_new: function (id, append){
			if (confirm(umoder_panel_params.confirm_activate)){
				if(!append){
					append = "bi";
				}
				_uPostForm('', {url:'/index/86-'+id +'-1',type:'GET'});
				var parentMarg = $("#"+append+id).parents('div.u-mpanel');		
				parentMarg.removeClass('moder-margin');						
				parentMarg.removeAttr('style');	
				parentMarg.removeAttr('onclick');
				parentMarg.removeClass('open');			
				parentMarg.mouseover(function(){
					bind_moder_over(parentMarg);
				});				
				parentMarg.mouseleave(function(){
					bind_moder_leave(parentMarg);
				});				
				$("#bi"+id).parents('li.u-mpanel-publ').remove();
			}
		}		


		var del_soc_item_new = del_soc_item_new?del_soc_item_new:function del_soc_item(id, as_spam){
            if (confirm(umoder_panel_params.confirm_delete)){                   
            	_uPostForm('',{url:'/index',type:'POST',data:{ssid:umoder_panel_params.ssid,a:'38',s:id, soc_type: scurrent, sdata: ssdata[scurrent], as_spam: (as_spam ? 1 : 0) }});
            }
		}
		var del_item_new = del_item_new ? del_item_new:function (id,as_spam){
            if (confirm(umoder_panel_params.confirm_delete)){
                _uPostForm('',{url:'/index',type:'POST',data:{ssid:umoder_panel_params.ssid,a:'38',s:id,as_spam:(as_spam?1:0)}});
            }
		}	
			

		if(!moderClass) var moderClass = [];


		function bind_moder_over(parentMarg){		
			parentMarg = $(parentMarg);						
 			if (!parentMarg.hasClass('open')) parentMarg.addClass('open');
 			if(timerId) clearTimeout(timerId);
		}

		function bind_moder_leave(parentMarg){	
			parentMarg = $(parentMarg);		
			timerId = setTimeout(function () { parentMarg.removeClass('open'); }, 500);
		}
		function bind_moder_hover(elem){		
			var par = $(elem).parents('div.u-mpanel');
			par.removeClass('open');
			par.attr('onmouseout', 'bind_moder_leave(this)');
			par.attr('onmouseover', 'bind_moder_over(this)');
			par.removeAttr('onclick');

		}

		function bind_moder_click(e){ 				
 			var par  = $(e).parent();	 				
 			if (par.hasClass('open')) { 					
 				par.removeClass('open'); 			
 				par.removeClass('moder-hover');		
 				if (par.hasClass('moder-margin')){
 					par.removeAttr('style');				
 				}	
 			} else {
 				par.addClass('open'); 					
 				if (par.hasClass('moder-margin')){
					var direction = par.hasClass('up-left')?'left':'right'; 
					par.attr("style", "margin-"+ direction +":"  + par.attr('data-marg')+ "px!important;");		
 				}
 			}
		};	