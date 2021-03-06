//
//  UIHelper.swift
//  FormView
//
//  Created by 黄伯驹 on 21/01/2018.
//  Copyright © 2018 黄伯驹. All rights reserved.
//

struct UIHelper {
    static func generateImageView() -> UIImageView {
        let imageView = UIImageView()
        imageView.backgroundColor = UIColor(white: 0.9, alpha: 1)
        imageView.layer.cornerRadius = 3
        imageView.translatesAutoresizingMaskIntoConstraints = false
        return imageView
    }
    
    static func generateTitleLabel() -> UILabel {
        let titleLabel = UILabel()
        titleLabel.font = UIFont.boldSystemFont(ofSize: 20)
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        return titleLabel
    }
}
