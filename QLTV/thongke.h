void RunThongKe() {
    DrawBorderThongKe();
	
	curMenuMuonTra = -1;
	btnThongKeSachThuVien.isHover = true;
	btnThongKeSachThuVien.isChoose = true;
	//SetMenuMuonTraSelectss(btnThongKeSachThuVien.id);
	
    btnBackToMenu.draw();
    btnThongKeSachThuVien.draw();
    btnThongKeSachMuon.draw();
    btnTopTen.draw();
}

void SetMenuButtonSwitchs(int menuID){
	btnThongKeSachThuVien.isChoose = false;
	btnThongKeSachMuon.isChoose = false;
	btnTopTen.isChoose = false;
	
	if(menuID == btnThongKeSachThuVien.id){
		btnThongKeSachThuVien.isChoose = true;
	}else if(menuID == btnThongKeSachMuon.id){
		btnThongKeSachMuon.isChoose = true;
	}else if(menuID == btnTopTen.id){
		btnTopTen.isChoose = true;
	}
}

void SetMenuMuonTraSelectss(int menuID){
	if(curMenuMuonTra != menuID){
		curMenuMuonTra = menuID;
		curDGMT = NULL; 
		curDSMT = NULL;
		Edit = NULL;
		strcpy(mess, "");
		ClearLayoutMainMuonTra();
		SetMenuButtonSwitchs(curMenuMuonTra);
		
		if(curMenuMuonTra == btnThongKeSachThuVien.id){
			//DrawMuonSach();
		}else if(curMenuMuonTra == btnThongKeSachMuon.id){
			//DrawTraSach();
		}else if(curMenuMuonTra == btnTopTen.id){
			DrawTopTen();
		}
		
	}
}

void DrawBorderThongKe(){
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(250, 100, w, h);
	
	setlinestyle(SOLID_LINE, 0, 3);
	line(250, 0, 250, h);
	line(250, 100, w, 100);
	
}

void DrawThongKe(){
	DrawBorderThongKe();

	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
	setcolor(TEXT_TITLE_COLOR);
	outtextxy((w+250)/2 - textwidth(TopTen)/2, 50, TopTen);
	
	setfillstyle(SOLID_FILL, BG_COLOR);
	bar(255, 105, w, h);
	
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	
	char t[][20] = {"STT", "ISBN", "Ten sach", "So trang", "Tac gia", "NXB", "The loai", "So luot muon", "Thoi Gian"};
	
	setlinestyle(SOLID_LINE,0, 3);
	setcolor(BORDER_COLOR);
	rectangle(XTT[0], 200, XTT[8], 880);
	line(XTT[0], 280, XTT[8], 280);
	for(int i=0; i<8; i++){
		line(XTT[i], 200, XTT[i], 880);
		outtextxy((XTT[i+1]+XTT[i])/2 - textwidth(t[i])/2, 240-textheight(t[i])/2, t[i]);
	}
	
	TopSach topsach(DSDS);
//	DuyetDocGia(TreeDocGia, topsach);
//	topsach.sort();
	char ch[20];
	for(int i=0; i < (topsach.n < 10 ? topsach.n : 10); i++){
		itoa(i+1, ch, 10);
		outtextxy((XTT[0]+XTT[1])/2-textwidth(ch)/2, 300 + i*50, ch);
		outtextxy(XTT[1]+10, 300 + i*50, DSDS.nodes[topsach.list[i].indexDS]->ISBN);
		outtextxy(XTT[2]+10, 300 + i*50, DSDS.nodes[topsach.list[i].indexDS]->tensach);
		itoa(DSDS.nodes[topsach.list[i].indexDS]->sotrang, ch, 10);
		outtextxy(XTT[3]+20, 300 + i*50, ch);
		outtextxy(XTT[4]+10, 300 + i*50, DSDS.nodes[topsach.list[i].indexDS]->tacgia);
		itoa(DSDS.nodes[topsach.list[i].indexDS]->nxb, ch, 10);
		outtextxy((XTT[5]+XTT[6])/2-textwidth(ch)/2, 300 + i*50, ch);
		outtextxy(XTT[6]+10, 300 + i*50, DSDS.nodes[topsach.list[i].indexDS]->theloai);
		itoa(topsach.list[i].cnt, ch, 10);
		outtextxy((XTT[7]+XTT[8])/2-textwidth(ch)/2, 300 + i*50, ch);
	} 
}	

void ThongKeEvent(){
	if(curDGMT != NULL && curMenuMuonTra != btnTopTen.id) ItemMTEvent();
	
	ButtonEffect(btnBackToMenu);
	ButtonEffect(btnThongKeSachThuVien);
	ButtonEffect(btnThongKeSachMuon);
	ButtonEffect(btnTopTen);
	
	if(curMenuMuonTra == btnThongKeSachThuVien.id){
		ButtonEffect(btnTimMaDG);
		if(curDGMT != NULL) ButtonEffect(btnTimMaSach);
		if(canMT) ButtonEffect(btnXacNhanMuonSach);
	}else if(curMenuMuonTra == btnTraSach.id){
		ButtonEffect(btnTimMaDG);
		if(curMT != -1) {
			if(subWindow == XAC_NHAN_TRA_SACH){
				ButtonEffect(btnXacNhanTraSach);
				ButtonEffect(btnLamMatSach);
			}else if(subWindow == XAC_NHAN_LAM_MAT_SACH){
				ButtonEffect(btnXacNhanLamMatSach);
				ButtonEffect(btnHuyLamMatSach);
			}
			
		}
	}else if(curMenuMuonTra == btnTopTen.id){
		
	}
	
	if(GetAsyncKeyState(VK_LBUTTON)){
		if(curMenuMuonTra == btnTraSach.id) ItemMTClick();
		
		if(btnBackToMenu.isMouseHover(mx, my)){
			SetMenuSelect(0);
		}else if(btnThongKeSachThuVien.isMouseHover(mx, my)){
			SetMenuMuonTraSelectss(btnMuonSach.id);
		}else if(btnThongKeSachMuon.isMouseHover(mx, my)){
			SetMenuMuonTraSelectss(btnTraSach.id);
		}else if(btnTopTen.isMouseHover(mx, my)){
			SetMenuMuonTraSelectss(btnTopTen.id);
		}
		
		if(curMenuMuonTra == btnMuonSach.id){
			if(btnTimMaDG.isMouseHover(mx, my)){
				curDGMT = &SearchDocGia(TreeDocGia, edNhapMaDGMuonSach.toInt())->docgia;
				DrawThongTinDocGia();
			}
			
			if(edNhapMaDGMuonSach.isMouseHover(mx, my)){
				Edit = &edNhapMaDGMuonSach;
			}
			
			if(curDGMT != NULL){
				if(btnTimMaSach.isMouseHover(mx, my)){
					if(strlen(edNhapMaSachMuonSach.content) > 0){
						// tim Dau Sach co chua Ma Sach can tim
						curDSMT = GetDauSach(DSDS, edNhapMaSachMuonSach.content);
						if(curDSMT == NULL){
							curSachMT = NULL;
						}else{
							// curSachMT != NULL : always
							curSachMT = GetSach(curDSMT->First, edNhapMaSachMuonSach.content);
						}
						
						strcpy(edNhapNgayMuonSach.content, GetSystemDate());
						DrawThongTinSach();
					}
				}
				if(edNhapMaSachMuonSach.isMouseHover(mx, my)){
					Edit = &edNhapMaSachMuonSach;
				}
				if(curSachMT != NULL && canMT){
					if(edNhapNgayMuonSach.isMouseHover(mx, my)){
						Edit = &edNhapNgayMuonSach;
					}
					if(btnXacNhanMuonSach.isMouseHover(mx, my)){
						// Muon sach
						if(!CheckDate(edNhapNgayMuonSach.content)){
							strcpy(mess, "THONG BAO : Ngay muon khong hop le");
							DrawThongTinSach();
						}else if(CompareDate(edNhapNgayMuonSach.content, GetSystemDate()) > 0){
							strcpy(mess, "THONG BAO : Ngay muon khong the muon hon ngay hien tai");
							DrawThongTinSach();
						}else{
							// 0: DANG MUON
							MuonTra muon(curSachMT->MASACH, edNhapNgayMuonSach.content, "", 0);
							InsertLast_MuonTra(curDGMT->mt, muon);
							
							NodeSach *nodeSach = GetNodeSach(curDSMT->First, curSachMT->MASACH);
							Sach sach = nodeSach->sach;
							sach.trangthai = 1; 	// DA CHO MUON
							UpdateNodeSach(nodeSach, sach);
							
							// Tang so luot muon sach cua Dau Sach
							curDSMT->soluotmuon ++;
							
							curDSMT = NULL;
							curSachMT = NULL;
							canMT = false;
							
							memset(edNhapMaSachMuonSach.content, 0, sizeof(edNhapMaSachMuonSach.content));
							DrawThongTinDocGia();
						}
					}
				}
			}
			
		}else if(curMenuMuonTra == btnTraSach.id){
			if(btnTimMaDG.isMouseHover(mx, my)){
				curDGMT = &SearchDocGia(TreeDocGia, edNhapMaDGMuonSach.toInt())->docgia;
				DrawThongTinDocGia();
			}
			
			if(edNhapMaDGMuonSach.isMouseHover(mx, my)){
				Edit = &edNhapMaDGMuonSach;
			}
			
			if(curMT != -1 && curDGMT != NULL){
				if(edNhapNgayTraSach.isMouseHover(mx, my)){
					Edit = &edNhapNgayTraSach;
				}
				
				if(subWindow == XAC_NHAN_TRA_SACH){
					if(btnXacNhanTraSach.isMouseHover(mx, my)){
						if(!CheckDate(edNhapNgayTraSach.content)){
							strcpy(mess, "THONG BAO : Ngay nhap vao khong hop le");
							DrawThongTinSachTra(curMT);
						}else if(CompareDate(edNhapNgayTraSach.content, DSMT.mt[curMT].NgayMuon) < 0){
							strcpy(mess, "THONG BAO : Ngay tra sach khong the som hon ngay muon sach");
							DrawThongTinSachTra(curMT);
						}else if(CompareDate(edNhapNgayTraSach.content, GetSystemDate()) > 0){
							strcpy(mess, "THONG BAO : Ngay muon khong the muon hon ngay hien tai");
							DrawThongTinSach();
						}else{
							// 1: DA TRA 
							MuonTra tra(DSMT.mt[curMT].MASACH, DSMT.mt[curMT].NgayMuon, edNhapNgayTraSach.content, 1);
							Update_MuonTra(curDGMT->mt, tra);
							
							curDSMT = GetDauSach(DSDS, DSMT.mt[curMT].MASACH);
							
							NodeSach *nodeSach = GetNodeSach(curDSMT->First, DSMT.mt[curMT].MASACH);
							Sach sach = nodeSach->sach;
							sach.trangthai = 0; 	// CHO MUON DUOC
							UpdateNodeSach(nodeSach, sach);
								
							// test
//							nodeSach = GetNodeSach(curDSMT->First, DSMT.mt[curMT].MASACH);
//							printf("TT : %d \n", nodeSach->sach.trangthai);
							
							curDSMT = NULL;
							curMT = -1;
								
							memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
							DrawThongTinDocGia();
						}
						
					}else if(btnLamMatSach.isMouseHover(mx, my)){
						subWindow = XAC_NHAN_LAM_MAT_SACH;
						DrawThongTinSachTra(curMT);
					}
					
				}else if(subWindow == XAC_NHAN_LAM_MAT_SACH){
					if(btnXacNhanLamMatSach.isMouseHover(mx, my)){
						// 2: LAM MAT
						MuonTra tra(DSMT.mt[curMT].MASACH, DSMT.mt[curMT].NgayMuon, "", 2);
						Update_MuonTra(curDGMT->mt, tra);
							
						curDSMT = GetDauSach(DSDS, DSMT.mt[curMT].MASACH);
							
						NodeSach *nodeSach = GetNodeSach(curDSMT->First, DSMT.mt[curMT].MASACH);
						Sach sach = nodeSach->sach;
						sach.trangthai = 2; 	// DA THANH LY
						UpdateNodeSach(nodeSach, sach);
								
						curDSMT = NULL;
						curMT = -1;
						
						curDGMT->trangthai = 0; // KHOA THE DOC GIA
						UpdateDocGia(TreeDocGia, *curDGMT);
								
						memset(edNhapNgayTraSach.content, 0, sizeof(edNhapNgayTraSach.content));
						DrawThongTinDocGia();
					}else if(btnHuyLamMatSach.isMouseHover(mx, my)){
						subWindow = XAC_NHAN_TRA_SACH;
						DrawThongTinSachTra(curMT);
					}
				}
				
			}
		}else if(curMenuMuonTra == btnTopTen.id){
			
		}
	}
}	
