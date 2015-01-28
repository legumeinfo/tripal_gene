<?php
/**
 * @file
 * Describe default gene views
 */

/**
 * Implements hook_views_default_views().
 *
 * @ingroup tripal_gene
 */
function tripal_gene_views_default_views() {
    $views = array();

    // User View ("Search Biological Content") Remember, if you change
    // the name/path of this view, you also want to change it's
    // description in tripal_gene_search_biological_data_views()
  
    $view = tripal_gene_defaultvalue_user_genes();
    $view = tripal_make_view_compatible_with_external($view);
    $views[$view->name] = $view;

    // TODO? an admin view could be added here
    //$view = tripal_gene_defaultview_admin_genes();
    //$view = tripal_make_view_compatible_with_external($view);
    //$views[$view->name] = $view;
  
    return $views;
}

/**
 * Defines the gene user search default view.
 *
 * @ingroup tripal_gene
 */
function tripal_gene_defaultvalue_user_genes() {

	$view = new view();
	$view->name = 'gene';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'gene';
	$view->human_name = 'Gene';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Gene Search';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'none';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
	  'name' => 'name',
	  'abbreviation' => 'abbreviation',
	  'coordinate' => 'coordinate',
	  'start' => 'start',
	  'stop' => 'stop',
	  'gene_family' => 'gene_family',
	  'description' => 'description',
	);
	$handler->display->display_options['style_options']['default'] = 'name';
	$handler->display->display_options['style_options']['info'] = array(
	  'name' => array(
	    'sortable' => 1,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'abbreviation' => array(
	    'sortable' => 1,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'coordinate' => array(
	    'sortable' => 1,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'start' => array(
	    'sortable' => 1,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'stop' => array(
	    'sortable' => 0,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'gene_family' => array(
	    'sortable' => 1,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	  'description' => array(
	    'sortable' => 0,
	    'default_sort_order' => 'asc',
	    'align' => '',
	    'separator' => '',
	    'empty_column' => 0,
	  ),
	);
    /* Footer: Global: Result summary */
    $handler->display->display_options['footer']['result']['id'] = 'result';
    $handler->display->display_options['footer']['result']['table'] = 'views';
    $handler->display->display_options['footer']['result']['field'] = 'result';
    $handler->display->display_options['footer']['result']['label'] = 'results';
    $handler->display->display_options['footer']['result']['content'] = 'Displaying @start - @end of @total genes';
    /* No results behavior: Global: Text area */
    $handler->display->display_options['empty']['area']['id'] = 'area';
    $handler->display->display_options['empty']['area']['table'] = 'views';
    $handler->display->display_options['empty']['area']['field'] = 'area';
    $handler->display->display_options['empty']['area']['label'] = 'No results';
    $handler->display->display_options['empty']['area']['empty'] = TRUE;
    $handler->display->display_options['empty']['area']['content'] = 'No results found. ';
    $handler->display->display_options['empty']['area']['format'] = '1';
	/* Field: gene: Uniquename */
	$handler->display->display_options['fields']['uniquename']['id'] = 'uniquename';
	$handler->display->display_options['fields']['uniquename']['table'] = 'gene';
	$handler->display->display_options['fields']['uniquename']['field'] = 'uniquename';
	$handler->display->display_options['fields']['uniquename']['exclude'] = TRUE;
	/* Field: gene: genus */
	$handler->display->display_options['fields']['genus']['id'] = 'genus';
	$handler->display->display_options['fields']['genus']['table'] = 'gene';
	$handler->display->display_options['fields']['genus']['field'] = 'genus';
	$handler->display->display_options['fields']['genus']['exclude'] = TRUE;
	/* Field: gene: species */
	$handler->display->display_options['fields']['species']['id'] = 'species';
	$handler->display->display_options['fields']['species']['table'] = 'gene';
	$handler->display->display_options['fields']['species']['field'] = 'species';
	$handler->display->display_options['fields']['species']['exclude'] = TRUE;
	/* Field: gene: Name */
	$handler->display->display_options['fields']['name']['id'] = 'name';
	$handler->display->display_options['fields']['name']['table'] = 'gene';
	$handler->display->display_options['fields']['name']['field'] = 'name';
	$handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['name']['alter']['path'] = 'feature/[genus]/[species]/gene/[uniquename]';
	/* Field: gene: Common Name */
	$handler->display->display_options['fields']['abbreviation']['id'] = 'abbreviation';
	$handler->display->display_options['fields']['abbreviation']['table'] = 'gene';
	$handler->display->display_options['fields']['abbreviation']['field'] = 'abbreviation';
	$handler->display->display_options['fields']['abbreviation']['label'] = 'Species';
	$handler->display->display_options['fields']['abbreviation']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['abbreviation']['alter']['path'] = 'organism/[genus]/[species]';
	/* Field: gene: Coordinate */
	$handler->display->display_options['fields']['coordinate']['id'] = 'coordinate';
	$handler->display->display_options['fields']['coordinate']['table'] = 'gene';
	$handler->display->display_options['fields']['coordinate']['field'] = 'coordinate';
	$handler->display->display_options['fields']['coordinate']['label'] = 'Chromosome';
	/* Field: gene: START */
	$handler->display->display_options['fields']['start']['id'] = 'start';
	$handler->display->display_options['fields']['start']['table'] = 'gene';
	$handler->display->display_options['fields']['start']['field'] = 'start';
	/* Field: gene: END */
	$handler->display->display_options['fields']['stop']['id'] = 'stop';
	$handler->display->display_options['fields']['stop']['table'] = 'gene';
	$handler->display->display_options['fields']['stop']['field'] = 'stop';
	/* Field: gene: gene_family */
	$handler->display->display_options['fields']['gene_family']['id'] = 'gene_family';
	$handler->display->display_options['fields']['gene_family']['table'] = 'gene';
	$handler->display->display_options['fields']['gene_family']['field'] = 'gene_family';
	$handler->display->display_options['fields']['gene_family']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['gene_family']['alter']['path'] = 'chado_phylotree/[gene_family]';

        /* Field: gene: Bucket */
        $handler->display->display_options['fields']['actions']['id'] = 'actions';
        $handler->display->display_options['fields']['actions']['table'] = 'gene';
	$handler->display->display_options['fields']['actions']['field'] = 'actions';
	$handler->display->display_options['fields']['actions']['label'] = 'Basket';
	$handler->display->display_options['fields']['actions']['element_class'] = 'fix-width-50';
	$handler->display->display_options['fields']['actions']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['actions']['empty_zero'] = TRUE;
			    
	/* Field: gene: description */
	$handler->display->display_options['fields']['description']['id'] = 'description';
	$handler->display->display_options['fields']['description']['table'] = 'gene';
	$handler->display->display_options['fields']['description']['field'] = 'description';
	/* Filter criterion: gene: description */
	$handler->display->display_options['filters']['description']['id'] = 'description';
	$handler->display->display_options['filters']['description']['table'] = 'gene';
	$handler->display->display_options['filters']['description']['field'] = 'description';
	$handler->display->display_options['filters']['description']['operator'] = 'word';
	$handler->display->display_options['filters']['description']['exposed'] = TRUE;
	$handler->display->display_options['filters']['description']['expose']['operator_id'] = 'description_op';
	$handler->display->display_options['filters']['description']['expose']['label'] = 'description';
	$handler->display->display_options['filters']['description']['expose']['description'] = '(e.g. “Contains any word: proteasome”)';
	$handler->display->display_options['filters']['description']['expose']['use_operator'] = TRUE;
	$handler->display->display_options['filters']['description']['expose']['operator'] = 'description_op';
	$handler->display->display_options['filters']['description']['expose']['identifier'] = 'description';
	$handler->display->display_options['filters']['description']['expose']['remember_roles'] = array(
	  2 => '2',
	  1 => 0,
	  4 => 0,
	);
	$handler->display->display_options['filters']['description']['max_length'] = '40';
	/* Filter criterion: gene: gene_family */
	$handler->display->display_options['filters']['gene_family']['id'] = 'gene_family';
	$handler->display->display_options['filters']['gene_family']['table'] = 'gene';
	$handler->display->display_options['filters']['gene_family']['field'] = 'gene_family';
	$handler->display->display_options['filters']['gene_family']['exposed'] = TRUE;
	$handler->display->display_options['filters']['gene_family']['expose']['operator_id'] = 'gene_family_op';
	$handler->display->display_options['filters']['gene_family']['expose']['label'] = 'gene family';
	$handler->display->display_options['filters']['gene_family']['expose']['description'] = '(e.g. “is equal to: phytozome_10.54586494”)';
	$handler->display->display_options['filters']['gene_family']['expose']['use_operator'] = TRUE;
	$handler->display->display_options['filters']['gene_family']['expose']['operator'] = 'gene_family_op';
	$handler->display->display_options['filters']['gene_family']['expose']['identifier'] = 'gene_family';
	$handler->display->display_options['filters']['gene_family']['expose']['remember_roles'] = array(
	  2 => '2',
	  1 => 0,
	  4 => 0,
	);
	$handler->display->display_options['filters']['gene_family']['max_length'] = '40';
	/* Filter criterion: gene: Name */
	$handler->display->display_options['filters']['name']['id'] = 'name';
	$handler->display->display_options['filters']['name']['table'] = 'gene';
	$handler->display->display_options['filters']['name']['field'] = 'name';
	$handler->display->display_options['filters']['name']['operator'] = 'contains';
	$handler->display->display_options['filters']['name']['exposed'] = TRUE;
	$handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
	$handler->display->display_options['filters']['name']['expose']['label'] = 'gene name';
	$handler->display->display_options['filters']['name']['expose']['description'] = '(e.g. “contains: Glyma.15G005900")';
	$handler->display->display_options['filters']['name']['expose']['use_operator'] = TRUE;
	$handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
	$handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
	$handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
	  2 => '2',
	  1 => 0,
	  4 => 0,
	);
	$handler->display->display_options['filters']['name']['max_length'] = '40';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['path'] = 'search/gene';


    // End of exported code here 

    return $view;

}