#define pixman_add_trapezoids _cairo_pixman_add_trapezoids
#define pixman_color_to_pixel _cairo_pixman_color_to_pixel
#define composeFunctions _cairo_pixman_compose_functions
#define fbComposeSetupMMX _cairo_pixman_compose_setup_mmx
#define pixman_composite _cairo_pixman_composite
#define fbCompositeCopyAreammx _cairo_pixman_composite_copy_area_mmx
#define fbCompositeSolidMask_nx8888x0565Cmmx _cairo_pixman_composite_solid_mask_nx8888x0565Cmmx
#define fbCompositeSolidMask_nx8888x8888Cmmx _cairo_pixman_composite_solid_mask_nx8888x8888Cmmx
#define fbCompositeSolidMask_nx8x0565mmx _cairo_pixman_composite_solid_mask_nx8x0565mmx
#define fbCompositeSolidMask_nx8x8888mmx _cairo_pixman_composite_solid_mask_nx8x8888mmx
#define fbCompositeSolidMaskSrc_nx8x8888mmx _cairo_pixman_composite_solid_mask_src_nx8x8888mmx
#define fbCompositeSolid_nx0565mmx _cairo_pixman_composite_solid_nx0565mmx
#define fbCompositeSolid_nx8888mmx _cairo_pixman_composite_solid_nx8888mmx
#define fbCompositeSrc_8888RevNPx0565mmx _cairo_pixman_composite_src_8888RevNPx0565mmx
#define fbCompositeSrc_8888RevNPx8888mmx _cairo_pixman_composite_src_8888RevNPx8888_mmx
#define fbCompositeSrc_8888x0565mmx _cairo_pixman_composite_src_8888x0565mmx
#define fbCompositeSrc_8888x8888mmx _cairo_pixman_composite_src_8888x8888mmx
#define fbCompositeSrc_8888x8x8888mmx _cairo_pixman_composite_src_8888x8x8888mmx
#define fbCompositeSrcAdd_8000x8000mmx _cairo_pixman_composite_src_add_8000x8000mmx
#define fbCompositeSrcAdd_8888x8888mmx _cairo_pixman_composite_src_add_8888x8888mmx
#define fbCompositeSrc_x888x8x8888mmx _cairo_pixman_composite_src_x888x8x8888mmx
#define pixman_composite_trapezoids _cairo_pixman_composite_trapezoids
#define pixman_composite_tri_fan _cairo_pixman_composite_tri_fan
#define pixman_composite_tri_strip _cairo_pixman_composite_tri_strip
#define pixman_composite_triangles _cairo_pixman_composite_triangles
#define fbCopyAreammx _cairo_pixman_copy_area_mmx
#define pixman_fill_rectangle _cairo_pixman_fill_rectangle
#define pixman_fill_rectangles _cairo_pixman_fill_rectangles
#define pixman_format_create _cairo_pixman_format_create
#define pixman_format_create_masks _cairo_pixman_format_create_masks
#define pixman_format_destroy _cairo_pixman_format_destroy
#define pixman_format_get_masks _cairo_pixman_format_get_masks
#define pixman_format_init _cairo_pixman_format_init
#if defined(USE_MMX) && !defined(__amd64__) && !defined(__x86_64__)
#define fbHaveMMX _cairo_pixman_have_mmx
#endif
#define pixman_image_create _cairo_pixman_image_create
#define pixman_image_create_for_data _cairo_pixman_image_create_for_data
#define pixman_image_destroy _cairo_pixman_image_destroy
#define pixman_image_get_data _cairo_pixman_image_get_data
#define pixman_image_get_depth _cairo_pixman_image_get_depth
#define pixman_image_get_format _cairo_pixman_image_get_format
#define pixman_image_get_height _cairo_pixman_image_get_height
#define pixman_image_get_stride _cairo_pixman_image_get_stride
#define pixman_image_get_width _cairo_pixman_image_get_width
#define pixman_image_set_clip_region _cairo_pixman_image_set_clip_region
#define pixman_image_set_component_alpha _cairo_pixman_image_set_component_alpha
#define pixman_image_set_filter _cairo_pixman_image_set_filter
#define pixman_image_set_repeat _cairo_pixman_image_set_repeat
#define pixman_image_set_transform _cairo_pixman_image_set_transform
#define pixman_image_create_linear_gradient _cairo_pixman_image_create_linear_gradient
#define pixman_image_create_radial_gradient _cairo_pixman_image_create_radial_gradient
#define miIsSolidAlpha _cairo_pixman_is_solid_alpha
#define pixman_pixel_to_color _cairo_pixman_pixel_to_color
#define pixman_region_append _cairo_pixman_region_append
#define pixman_region_contains_point _cairo_pixman_region_contains_point
#define pixman_region_contains_rectangle _cairo_pixman_region_contains_rectangle
#define pixman_region_copy _cairo_pixman_region_copy
#define pixman_region_init _cairo_pixman_region_init
#define pixman_region_init_rect _cairo_pixman_region_init_rect
#define pixman_region_init_rects _cairo_pixman_region_init_rects
#define pixman_region_init_with_extents _cairo_pixman_region_init_with_extents
#define pixman_region_fini _cairo_pixman_region_fini
#define pixman_region_empty _cairo_pixman_region_empty
#define pixman_region_extents _cairo_pixman_region_extents
#define pixman_region_intersect _cairo_pixman_region_intersect
#define pixman_region_inverse _cairo_pixman_region_inverse
#define pixman_region_not_empty _cairo_pixman_region_not_empty
#define pixman_region_num_rects _cairo_pixman_region_num_rects
#define pixman_region_rects _cairo_pixman_region_rects
#define pixman_region_reset _cairo_pixman_region_reset
#define pixman_region_subtract _cairo_pixman_region_subtract
#define pixman_region_translate _cairo_pixman_region_translate
#define pixman_region_union _cairo_pixman_region_union
#define pixman_region_union_rect _cairo_pixman_region_union_rect
#define pixman_region_validate _cairo_pixman_region_validate
#define RenderEdgeInit _cairo_pixman_render_edge_init
#define RenderEdgeStep _cairo_pixman_render_edge_step
#define RenderLineFixedEdgeInit _cairo_pixman_render_line_fixed_edge_init
#define RenderSampleCeilY _cairo_pixman_render_sample_ceil_y
#define RenderSampleFloorY _cairo_pixman_render_sample_floor_y
