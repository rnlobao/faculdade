//
//  LoginModel.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 26/09/22.
//

import Foundation

struct Login: Codable {
    var email, password: String?
}

struct UserResponse: Codable {
    var id, login, email, createdAt: String
}

struct Response: Codable {
    var userResponse: UserResponse
    var token: String
}
