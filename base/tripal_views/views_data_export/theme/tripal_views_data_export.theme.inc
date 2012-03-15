<?php

function template_preprocess_views_data_export_fasta_body(&$vars) {
   _views_data_export_header_shared_preprocess($vars);
   _views_data_export_body_shared_preprocess($vars);
   $defline_tpl = $vars['options']['defline_fields'];

   // iterate through the rows and replace the field tokens with values
   // to generate the definition line
   foreach ($vars['themed_rows'] as $i => $fields) {
      $defline = $defline_tpl;
      foreach ($fields as $key => $value) {
         $defline = preg_replace("/\[$key\]/",$value,$defline);
      }
      $vars['themed_rows'][$i]['defline'] = $defline;
   }
}