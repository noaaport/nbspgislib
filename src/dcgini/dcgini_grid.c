void nesdis_proj_str_lonlat_ij(struct nesdis_proj_str_st *pstr,
			       double lon_deg,
			       double lat_deg,
			       double *ii,
			       double *jj){
  double lon_rad, lat_rad;
  double x, y;
  double r;

  lon_rad = lon_deg * RAD_PER_DEG;
  lat_rad = lat_deg * RAD_PER_DEG;

  r = RE_METERS * tan(M_PI_4 - 0.5 * pstr->s * lat_rad);
  x = r * sin(lon_rad - pstr->lov_rad);
  y = -pstr->s * r * cos(lon_rad - pstr->lov_rad);

  *ii = (x - pstr->x1)/pstr->dx;
  *jj = (y - pstr->y1)/pstr->dy;
}

void nesdis_proj_llc_lonlat_ij(struct nesdis_proj_llc_st *pllc,
			       double lon_deg,
			       double lat_deg,
			       double *ii,
			       double *jj){
  double lon_rad, lat_rad;
  double x, y;
  double a, b;

  lon_rad = lon_deg * RAD_PER_DEG;
  lat_rad = lat_deg * RAD_PER_DEG;

  a = pow(tan(M_PI_4 - 0.5 * pllc->s * lat_rad), pllc->cos_psi);
  b = pllc->cos_psi * (lon_rad - pllc->lov_rad);
  x = pllc->r_E * a * sin(b);
  y = -pllc->s * pllc->r_E * a * cos(b);

  *ii = (x - pllc->x1)/pllc->dx;
  *jj = (y - pllc->y1)/pllc->dy;
}

void nesdis_proj_mer_lonlat_ij(struct nesdis_proj_mer_st *pmer,
			       double lon_deg,
			       double lat_deg,
			       double *ii,
			       double *jj){
  double lon_rad, lat_rad;
  double r1, r2;
  double b, d;
  double n;

  lon_rad = lon_deg * RAD_PER_DEG;
  lat_rad = lat_deg * RAD_PER_DEG;

  d = lon_rad - pmer->lon0_rad;
  r1 = tan(lat_rad);
  r2 = cos(d);
  b = cos(lat_rad) * sin(d);  
  x = 0.5 * log((1.0 + b)/(1.0 - b));
  y = atan2(r1, r2);

  *ii = (x - pmer->x1)/pmer->dx;
  *jj = (y - pmer->y1)/pmer->dy;
}
