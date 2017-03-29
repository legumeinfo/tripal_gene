/* add linkout to intepro IPRxxxxxx codes in the description. */

'use strict';

jQuery(document).ready( function($) {
	var commentEl = $('#gene-description');
	var comment = commentEl.html();
	var matches = comment.match(/IPR\d{6,6}/gi);
    if (matches != null) {
        matches.forEach(function(code) {
            var link = '<a href="http://www.ebi.ac.uk/interpro/entry/'+ code +
                            '">'+code + '</a>';
            comment = comment.replace(code, link);
        });
        commentEl.html(comment);
    }
});
