<?php
// $Id$

/*************************************************************************
 * Purpose: Provide Guidance to new Tripal Admin
 *
 * @return HTML Formatted text
 */
function tripal_stock_module_description_page() {
  $text = '';
  
  $text .= '<h3>Description:</h3>';
  //================================================================================
  $text .= '<p>The Tripal Stock Module provides functionality for adding, editing, deleting and accessing chado stocks. The stock module was designed to store information about stock collections in a laboratory. What is called a stock could also be called a strain or an accession. There is a lot in common between a Drosophila stock and a Saccharomyces strain and an Arabidopsis line. They all come from some taxon, have genotypes, physical locations in the lab, some conceivable relationship with a publication, some conceivable relationship with a sequence feature (such as a transgene), and could be described by some ontology term. For more information about the chado Stock Module <a href="http://gmod.org/wiki/Chado_Stock_Module">see the GMOD Wiki Page</a></p>';
  
  $text .= '<h3>Post Installation Steps:</h3>';
  //================================================================================
  $text .= '<p>Since at the time of this modules developement there is no accepted ontology for describing stocks, their properties and relationships, this module allows you to select the controlled vocabularies (CVs) in your Chado Database you would like to govern these data.</p>';
  $text .= '<b>To Set the Controlled Vocabularies for Stocks:</b>';
    $text .= '<ol>';
      $text .= '<li>Ensure your Controlled Vocabulary is in Chado</li>';
      $text .= '<ol type="i">';
        $text .= '<li>Load your Ontology into Chado using the <a href="tripal_cv/ontology_loader">Tripal Ontology Loader</a></li>';
        $text .= '<li> Create your ontology from scratch by first <a href="tripal_cv/add_cv">creating a controlled vocabulary</a> and then <a href="tripal_cv/add_cvterm">adding terms to it</a>.</li>';
      $text .= '</ol>';
    $text .= '<li>Then go to the <a href="tripal_stock/configuration">Configuration Page for Stocks</a> and, in the "Set Stock Controlled Vocabularies" Fieldset, select the Controlled Vocaulary name for Stock Types, Stock Properties and Stock Relationship Types.</li>';
      $text .= '<ol type="i">';
        $text .= '<li>Stock Types: When you are creating stocks, the type of each stock must be indicated. This might include "DNA extraction", "Individual Plant/Animal" or even "Progeny Population".</li>';
        $text .= '<li>Stock Properties: This module also allows you to assign properties to any stock. Each property has a type and a value where type is required an value is not. Therefore, if you want to say that a stock was grown at 23 degrees Celcius then the Type would be "temperature grown at" and the value would be 23 degrees Celcius. As such the Stock Properties controlled vocabulary might include "temperature grown at", "diet", "extraction date", "stock location", etc.</li>';
        $text .= '<li>Stock Relationship Types: You can also specify relationships between stocks. For example, a stock of type="DNA extraction" (Stock 1a) is related to the stock of type="Individual Plant/Animal" (Stock 1) that it was extracted from. Thus you might specify the relationship Stock 1 is the source material for Stock 1a where the relationship type is "is the source material for". As such Stock Relationship Types might include "is the source material for", "is maternal parent of", "is individual of population", etc.</li>';
      $text .= '</ol>';
    $text .= '</ol>';
  
  $text .= '<p>This module also provides <b>User Permissions</b> to control which users or groups of users (roles) can view/access stock content (access chado_stock content), create stocks (create chado_stock content), edit or delete stocks (edit chado_stock content or delete chado_stock content). The default is that only the original administration account has these permissions. To allow additional users/roles any combination of the above permissions:</p>';
  $text .= '<ol>';
    $text .= '<li><a href="../user/roles">Add Roles</a> to provide permissions to. For example, you might want a "View Tripal Stock Content" and a "Manage Tripal Stock Content" Role. If you only want to provide permissions based on whether the user is logged in (authenticated) or not (anonymous) then you don\'t need to create roles.</li>';
    $text .= '<li><a href="../user/permissions">Assign permissions</a> to roles. Specically focus on those mentioned above, then for each permission add a checkmark to the rolw (columns) that you want to have this permission.</li>';
    $text .= '<li><a href="../user/user">Assign Users Roles</a>. This is what gives a given user the set of permissions associated with a given role. Notice that you can assign more than one role to a user and that each user is "Authenticated" by default. A user has permission is any of his/her roles have that permission.</li>';
  $text .= '</ol>';
  
  $text .= '<p>Another important step, <b>if you chado database already contains stocks, is to sync\' Chado with Drupal</b>. This creates Drupal Content including detail pages for each stock (known as nodes in Drupal). To sync\' Chado with Drupal simply go to the <a href="tripal_stock/configuration">Configuration Page for Stocks</a> and in the "Sync Stocks" Fieldset select the Organisms whose associated stocks you would like to sync. If this list doesn\'t contain an organism which you know is in Chado go to the Organism Configuration Page and make sure it is sync\'d with Drupal.</p>';
  
  $text .= '<h3>Features of this Module:</h3>';
  //================================================================================
  $text .= '<b><a href="../../node/add/chado_stock">Create a Generic Stock:</a></b>';
  $text .= '<p>This allows you to create content in your drupal and chado for a stock (only the unique stock identifier is duplicated). A Generic Stock must have a unique name, a type and an organism. In addition, you can optionally supply a more human-readable name, a primary database reference and even a short description. The Create Generic Stock form is a multistep form with the first step creating the Basic stock (stored in the stock table). All the remaining steps are optional and descriptions of each follow:</p>';
      $text .= '<ol type="i">';
        $text .= '<li>The Next Step is to Add Properties to the newly created stock. Properties allow you to specify additional details about a given stock. Since the types of properties you can add are goverened by a controlled vocaulary that you can create, you have complete control over what additional properties you want to allow.</li>';
        $text .= '<li>Then you can Add External Database References. A Database Reference can be thought of as a synonym for the current stock where you want to specify a source for that synonym. The source would then be thought of as the database where a database can either be online and provide automatic linking out to the synonymous record or offline and simply be a text name of the source. To create a database reference with a given source you must first add the database to chado <a href="tripal_db/add_db">here</a>.</li>';
        $text .= '<li>Finally you can Add Relationships between Stocks. This allows you to specify, for example, the source material of a stock or one of it\'s parents. To create a relationship between your newly added stock and another stock, the other stock must first be created as this one was. Also, since the types of relationships is governed by a controlled vocabulary, just like with properties you have complete control over which relationships you want to allow. Once you click "Finish" you will be re-directed to the Details Page of the new Stock.</li>';
      $text .= '</ol>';
      
  $text .= '<b>Details Page of a Stock:</b>';
  $text .= '<p>Each stock get\'s it\'s own page on this website. This page is meant to give an overall picture of the stock including listing the basic details, as well as, all properties, database references and relationships. To understand where it is -All page content in Drupal is known as a node and is given a unique identifier or nid. Thus every drupal page has a path of node/<nid>. You can get to the Details page for a given stock from either of the stock listings described below.</p>';
  $text .= '<p>If you want to customize the look of the stock Details page simply copy the PHP/HTML template node-chado_stock.tpl.php from theme_tripal to the base theme you are currently using. Then edit it as desired. There are plans to integrate this details page with Drupal Panels which will provide a much more user-friendly and no-programming-needed method to customize this page.</p>';
  
  $text .= '<b>Adding/Updating/Deleting Stocks and their Properties, Database References and Relationships:</b>';
  $text .= '<p>The Stock Details Page also acts as a landing pad for updating/deleting stocks. To <b>update a stock</b>, go to the stocks details page and click on the Edit tab near the top of the page. This tab will only be visable if you have permission to edit chado stock content (See post installation steps above for information on setting user permissions). If you want to <b>delete a stock</b>, click the Edit tab and then near the bottom of the form, click the Delete button. This will delete the entire stock including it\'s properties, database references and any relationships including it.</p>';
  $text .= '<p>To <b>update/delete a given property of a stock</b>, click the "Edit Properties" Tab near the top of the stock details page. This form provides a listing of all existing properties for the given stock with form elements allowing you to change their value. After editing the properties you wanted to, simply click the "Update Properties" button to update all the properties for that stock. To delete a given property simply click the "Delete" Button beside the property you want to delete. You cannot undo this action! To <b>add a property to the given stock</b> simply fill out the "Add Property" form at the bottom of the "Edit Properties" Tab.</p>';
  $text .= '<p><b>Adding, updating and deleting Database References and Relationships</b> for a given stock is exactly the same as the method for properties. To edit Database References, click the "Edit DB References" tab and to add/edit/update stock relationships, click the "Edit Relationships" tab.</p>';
  
  $text .= '<b><a href="../../stocks">Basic Listing of Stocks:</a></b>';
  $text .= '<p>This module also provides a basic listing of all stocks currently sync\'d with Drupal. To access this listing, there should be a Stocks Primary Menu item which links you to <a href="../../stocks">this page</a>. This page lists each stock on it\'s own row and provides a link to each stock by clicking on it\'s name. Currently there is no way to easily customize this listing.</p>';
  
  $text .= '<b><a href="../build/views/">Flexible Listing of Stocks using Drupal Views:</a></b>';
  $text .= '<p>In order to access a more flexible listing of stocks you must first install the <a href="http://drupal.org/project/views">Drupal Views2 module</a>. You should then be able to access the default views <a href="../build/views/">here</a>. Essentially, Views is a module which allows you to create custom SQL queries completely through the web interface without knowing SQL. Furthermore, it also does some formatting of the results allowing you to display them as HTML lists, tables or grids. You can also expose filters to the user to let them customize the results they see and even implement various sorting.</p>';
  $text .= '<p>To use one of the Default Views simply click "Enable" and then "Edit" to change it to show exactly what you want. To view the current listing simply clikc "View Page" at the top of the Edit user interface. There are a number of good tutorials out there for Views2, any of which can be used to help you create your own custom listings of biological content. (Note: there aren\'t any tutorials specifically for tripal content but any tutorial for Views2 will show you how to use the views interface.</p>';
  
  
  return $text;
}

/*************************************************************************
 * Purpose: Provide administration options for chado_stocks
 *
 * @return form array (as described by the drupal form api)
 */
function tripal_stock_admin() {
  $form = array();

   // before proceeding check to see if we have any
   // currently processing jobs. If so, we don't want
   // to give the opportunity to sync Stocks
   $active_jobs = FALSE;
   if(tripal_get_module_active_jobs('tripal_stock')){
      $active_jobs = TRUE;
   }
   if($active_jobs){
   
   $form['notice'] = array(
         '#type' => 'fieldset',
         '#title' => t('Stock Management Temporarily Unavailable')
      );

   $form['notice']['message'] = array(
         '#value' => t("Currently, stock management jobs are waiting or ".
            "are running. Managemment features have been hidden until these ".
            "jobs complete.  Please check back later once these jobs have ".
            "finished.  You can view the status of pending jobs in the Tripal ".
            "jobs page."),
      );

   } else {

   // SET Vocabularies -----------------------------------------------------------------------------------------
   $form['set_cv'] = array(
      '#type' => 'fieldset',
      '#title' => t('Set Stock Controlled Vocabularies'),
      '#weight' => -10
   );   
   
   $form['set_cv']['message'] = array(
         '#value' => t("This setting allows you to set which chado controlled vocabularies (cv)"
	              ." are used. Cvs are used to control user input for the type of stock,"
		      ." any properties they enter for a stock & the types of relationships"
		      ." between stocks. Only cvs already loaded into chado can be selected here.")
   );

   $cv_options = tripal_cv_get_cv_options();
   
   $form['set_cv']['stock_types_cv'] = array(
     '#type' => 'select',
     '#title' => t('Controlled Vocabulary governing Stock Types'),
     '#options' => $cv_options,
     '#default_value' => variable_get('chado_stock_types_cv', 0)
   );

   $form['set_cv']['stock_prop_types_cv'] = array(
     '#type' => 'select',
     '#title' => t('Controlled Vocabulary governing Types of Stock Properties'),
     '#description' => t("This cv must contain a cvterm entry where name='synonym'."),
     '#options' => $cv_options,
     '#default_value' => variable_get('chado_stock_prop_types_cv', 0)
   );

   $form['set_cv']['stock_relationship_cv'] = array(
     '#type' => 'select',
     '#title' => t('Controlled Vocabulary governing Types of Relationsips between Stocks'),
     '#options' => $cv_options,
     '#default_value' => variable_get('chado_stock_relationship_cv', 0)
   );

   $form['set_cv']['button'] = array(
      '#type' => 'submit',
      '#value' => t('Set Controlled Vacabularies')
   );

   // SYNC STOCKS-----------------------------------------------------------------------------------------------
   $form['sync'] = array(
      '#type' => 'fieldset',
      '#title' => t('Sync Stocks'),
      '#weight' => -10
   );

   $form['sync']['description'] = array(
      '#type' => 'item',
      '#value' => t("Click the 'Sync all Germplasm' button to create Drupal ".
         "content for stocks in chado. Depending on the ".
         "number of stocks in the chado database this may take a long ".
         "time to complete. ")
   );

   $form['sync']['organisms'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Organisms for which Stocks should be sync\'d'),
      '#description' => t('Only sync\'d Organisms are listed. Leaving an organism unchecked does not delete already sync\'d Stocks.'),
      '#options' => tripal_organism_get_organism_options(),
      '#required'    => FALSE,
      '#prefix'      => '<div id="lib_boxes">',
      '#suffix'      => '</div>'
   );

   $form['sync']['button'] = array(
      '#type' => 'submit',
      '#value' => t('Sync Stocks')
   );
}

  return system_settings_form($form);

}

/**
 * Implements hook_form_submit()
 *
 * Handles Submit actions of all subforms
 */
function tripal_stock_admin_validate($form, &$form_state) {
   global $user;  // we need access to the user info
   $job_args = array();

   // Sync Stocks
   if ($form_state['values']['op'] == t('Sync Stocks')) {
      // Array organism_id => organims common_name
      //  which only includes those organisms which the user wants to select stocks for
      $organisms_2b_syncd = $form_state['values']['organisms'];

      //for each organism selected submit job (handled by tripal_stock_sync_stock_set)
      //  which syncs all stocks with an organism_id equal to the selelcted organism
      foreach ( $organisms_2b_syncd as $organism_id ) {
        if($organism_id != 0) {
          $job_args[0] = $organism_id;
          tripal_add_job("Sync Stocks from Organism $organism_id",'tripal_stock',
            'tripal_stock_sync_stock_set',$job_args,$user->uid);
        }
      }
    }

    if ($form_state['values']['op'] == t('Set Controlled Vacabularies')) {
      variable_set('chado_stock_types_cv', $form_state['values']['stock_types_cv']);
      variable_set('chado_stock_prop_types_cv', $form_state['values']['stock_prop_types_cv']);
      variable_set('chado_stock_relationship_cv', $form_state['values']['stock_relationship_cv']);
    }
}

/**************************************************************************************************************/
/** 
 * Syncs all Stocks associated with an organism
 * Note: Handling of multiple organisms is done in tripal_stock_admin_validate()
 *
 * @params $organisms
 */
 function tripal_stock_sync_stock_set($organism_id, $job_id) {
	global $user;

	if(!$organism_id) {
		print '0 Stocks to Sync -No Organisms Selected.\n';
	} else {

		// Get list of stocks to sync
		$previous_db = tripal_db_set_active('chado');
    $result = db_query(
       "SELECT stock_id, uniquename, type_id, organism_id FROM stock WHERE organism_id=%d",
       $organism_id
    );
    tripal_db_set_active($previous_db);

    $stocks_created_count = 0; //keeps track of total number of stocks successfully created
    $stocks_attempted = 0;
    // foreach stock to be sync'd -> create node & add stock_id
    while ( $r = db_fetch_object($result) ) {
      // $r is the current stock to be sync'd
      $stocks_attempted++;

      print 'Processing '.$r->uniquename."\n";

      // check not already in drupal
      $in_drupal_query = db_query(
      	"SELECT * FROM {chado_stock} WHERE stock_id=%d",
	 			$r->stock_id
      );
      if ( !db_fetch_object($in_drupal_query) ) {

        //create new chado_stock node
        $new_node = new stdClass();
	 			$new_node->type = 'chado_stock';
        $new_node->uid = $user->uid;
	 			$new_node->title = $r->uniquename;
	 			$new_node->type_id = $r->type_id;
	 			$new_node->organism_id = $r->organism_id;
	 			$new_node->stock_id = $r->stock_id;
	 			//print 'New Node:';
	 			//print_r($new_node);
	 			
	 			node_validate($new_node);
	 			
        if(!form_get_errors()){
	    		//print 'Try to Create Node ';
        	$node = node_submit($new_node);
          node_save($node);
          if($node->nid){
          	$stocks_created_count++;
	 
						//Add stock id to chado_stock table
	 					db_query(
	   	  			"UPDATE {chado_stock} SET stock_id=%d WHERE nid=%d AND vid=%d",
	   	  			$r->stock_id,
	   	  			$node->nid,
	   	  			$node->vid
	 					);
          }
        } else {
        	print "\tCreate Stock Form Errors: ";
	 				print_r(form_get_errors());
        }
	 			print "\n\tNid=".$node->nid."\n";
			} else {
				print "\tSkipped $r->uniquename because it's already in drupal.\n";
      } //end of if not already in drupal
    } //end of while still stocks to be sync'd
  } //end of if organism_id not supplied
   
  if ($stocks_attempted == 0) {
		print "No stocks retrieved for organism (".$organism_id.")\n";
		return 1;
	} else {
		if ($stocks_created_count > 0) {
			print "$stocks_created_count Stocks Successfully Created\n";
			return 1;
		} else {
			return 0;
		}
	}
}